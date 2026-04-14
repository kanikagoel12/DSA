#include<bits/stdc++.h>
using namespace std;

/* memoisation */
int solve(vector<int>& nums,int idx,vector<int>& dp){
    if(idx >= nums.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    return dp[idx] = max(nums[idx] + solve(nums,idx+2,dp),solve(nums,idx+1,dp));
}

int rob(vector<int>& nums) {
    //vector<int> dp(nums.size()+1,-1);
    vector<int> dp(nums.size()+2,0);
    int n = nums.size();
    for(int i=n-1;i>=0;i--){
        dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
    }
    return dp[0];
}

int main()
{
    vector<int> nums = {1,2,3,1};
    int res = rob(nums);
    cout<<res<<endl;
}