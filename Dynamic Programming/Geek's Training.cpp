#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat,int lastActivity,int day,vector<vector<int>>& dp){

    if(day==mat.size()) return 0;

    if(dp[day][lastActivity]!=-1)
        return dp[day][lastActivity];

    int res = 0;
    for(int i=0;i<mat[day].size();i++){

        if(i!=lastActivity){
            res=max(res,mat[day][i] + solve(mat,i,day+1,dp));
        }
    }
    return dp[day][lastActivity] = res;
}

int maximumPoints(vector<vector<int>>& mat) {
    // code here
    vector<vector<int>> dp(mat.size(),vector<int>(4,-1));
    return solve(mat,3,0,dp);
}

int main()
{
    vector<vector<int>> mat = {{1,2,5},{3,1,1},{3,3,3}};
    int res = maximumPoints(mat);
    cout<<res<<endl;
    return 0;
}