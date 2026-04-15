#include<bits/stdc++.h>
using namespace std;

int solveRec(int i,int j,int m,int n){
    if(i==m-1 and j==n-1) return 1;
    if(i==m or j==n) return 0;

    return solveRec(i+1,j,m,n)+solveRec(i,j+1,m,n);
}

int solveMem(int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i==m-1 and j==n-1) return 1;
    if(i==m or j==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = solveMem(i+1,j,m,n,dp)+solveMem(i,j+1,m,n,dp);
}

int solveTab(int i,int j,int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i<m-1)
                dp[i][j] += dp[i+1][j];
            if(j<n-1)
                dp[i][j] += dp[i][j+1];
        }
    }
    return dp[0][0];
}

int solveSO(int i,int j,int m,int n)
{
    vector<int> next(n,0);
    for(int i=m-1;i>=0;i--){
        vector<int> curr(n,0);
        for(int j=n-1;j>=0;j--){
            if(i==m-1 and j==n-1) {
                curr[j]=1;
            }
            if(i<m-1)
                curr[j] += next[j];
            if(j<n-1)
                curr[j] += curr[j+1];
        }
        next=curr;
    }
    return next[0];
}

int main()
{
    int m=3;
    int n=7;
    cout<<solveRec(0,0,m,n)<<endl;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<solveMem(0,0,m,n,dp)<<endl;
    cout<<solveTab(0,0,m,n)<<endl;
    cout<<solveSO(0,0,m,n)<<endl;

    return 0;
}