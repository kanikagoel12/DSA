#include <bits/stdc++.h>
using namespace std;

double solve(double x,long n){
    if(n==0) return 1;
    if(n==1) return x;

    if(n%2==0){
        return solve(x*x,n/2);
    }

    return x*solve(x,n-1);
}
double myPow(double x, int n) {
    long N=n;
    if(n<0){
        N=(long)n*-1;
        x=(1/x);
    }
    return solve(x,N);
}

int main()
{
    double x=2.00;
    int n=10;
    cout<<myPow(x,n);
}