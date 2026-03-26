#include<bits/stdc++.h>
using namespace std;


void solve(string s,int i,bool fnd,long long &num,int &sign){
    if(i==s.length()) return;
    if(num>INT_MAX){
        return;
    }
    if(s[i]>='0' and s[i]<='9'){
        num=(num*10)+(s[i]-'0');
        fnd=true;
        //cout<<num<<endl;
        solve(s,i+1,fnd,num,sign);
    }
    else if(s[i]==' '){
        if(!fnd and sign==0){
            solve(s,i+1,fnd,num,sign);
        }
        else{
            return;
        }
    }
    else if(s[i]=='-'){
        if(!fnd and sign==0){
            sign=-1;
            solve(s,i+1,fnd,num,sign);
        }
        else{
            return;
        }
    }
    else if(s[i]=='+'){
        if(!fnd and sign==0){
            sign=1;
            solve(s,i+1,fnd,num,sign);
        }
        else{
            return;
        }
    }
}
int myAtoi(string s) {
    long long num=0;
    int sign=0;
    solve(s,0,false,num,sign);
    long long ans = num*((sign==-1)?-1:1);
    if(ans<INT_MAX and ans>INT_MIN){
        return ans;
    }
    else if(ans>=INT_MAX){
        return INT_MAX;
    }
    else{
        return INT_MIN;
    }
}

int main()
{
    string s = "42";
    cout<<myAtoi(s);
}