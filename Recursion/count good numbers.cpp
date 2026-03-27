#include<bits/stdc++.h>
using namespace std;

int mod=(int)(1e9+7);
long long solve(long long x,long long n){
    if(n==0) return 1;
    if(n==1) return x;

    if(n%2==0){
        return solve((x*x)%mod,n/2)%mod;
    }

    return (x*solve(x,n-1))%mod;
}
int countGoodNumbers(long long n) {
    int mul = solve(20,n/2);
    if(n%2==1){
        mul=(1LL*mul*5)%mod;
    }
    return mul%mod;
}

int main()
{
    int n=10;
    cout<<countGoodNumbers(n);
}