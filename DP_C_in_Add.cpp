#include<bits/stdc++.h>
using namespace std;

struct GP
{
    bool g;
    bool p;
};
GP backcell(GP upprer,GP lower){
    GP res;
    res.g=upprer.g||(upprer.p&&lower.g);
    res.p=upprer.p && lower.p;
    return res;
}

int binToDec(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') ans+=pow(2,i);
    }
    return ans;
}

string dec_to_bin(int a)
{
    string s;
    int t;
    while (a>0){
        t=a%2;
        s+=t+'0';
        a/=2;
    }
    while(s.length()<16) s+=0+'0';
    return s;
}

int main()
{
    int a; 
    int b;
    cin>>a;
    cin>>b; 
    string stra=dec_to_bin(a);
    string strb=dec_to_bin(b);

    // cout<<stra;
    // cout<<"\n";
    // cout<<strb;
    // cout<<"\n";

    vector<GP> curr(stra.length()+1);
    for(int i=0;i<stra.length();i++){
        int bita=stra[i]-'0';
        int bitb=strb[i]-'0';
        curr[i+1].g=bita && bitb;
        curr[i+1].p=bita || bitb;
    }
    //Gi,j = Gi,k + Pi,k*Gk-1,j
    //Pi,j=Pi,k*Pk-1,j
    for(int L=0; L<4;L++)
    {
        vector<GP>next=curr;
        int blocksize=1<<(L+1);
        int halfsize=1<<L;
        for(int i=1; i<17;i++){
            int pos=i%blocksize;
            if(pos>=halfsize)
            {
                int k_index=(i/blocksize)*blocksize+halfsize-1;
                next[i]=backcell(curr[i],curr[k_index]);
            }
        }
        curr=next;
    }
    string ans="";
    for(int i=0; i<16;i++){
        int bita=stra[i]-'0';
        int bitb=strb[i]-'0';
        int bitC=curr[i].g;
        int t=bita^bitb^bitC;
        ans+=(t+'0');
    }
    cout<<"\n";
    cout<<binToDec(ans);
}
