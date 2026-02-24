#include<bits/stdc++.h>
using namespace std;



int binToDec(string s){
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') ans+=pow(2,i);
    }
    return ans;
}
string shiftleff(string s){
    string ans="";
    for(int i=1;i<s.length();i++){
        ans+=s[i];
    }
    ans+="0";
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
    while(s.length()<8) s+="0";
    reverse(s.begin(),s.end());

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
    cout<<stra;
    cout<<"\n";
    cout<<strb;
    cout<<"\n";
    string ans="";
    string R="";
    for(int i=0;i<stra.length();i++){
        R=shiftleff(R);
        R[R.length()-1]=stra[i];
        int intR=binToDec(R);
        int B=binToDec(strb);
        int D=intR-B;
        if(D<0){
            ans+="0";

        }else{
            intR-=B;
            ans+="1";
        }
        R=dec_to_bin(intR);
    }
    cout<<"\n";
    cout<<binToDec(ans);
    cout<<"\n";
    cout<<"Dư "<<binToDec(R);
}
