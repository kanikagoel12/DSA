#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int idx,vector<int>& dp){
    if(idx>=nums.size()){
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];

    return dp[idx] = max(solve(nums,idx+2,dp)+nums[idx],solve(nums,idx+1,dp));
}

int rob(vector<int>& nums) {
    if(nums.size()==1) return nums[0];
    vector<int> dp1(nums.size(),-1);
    vector<int> dp2(nums.size(),-1);
    vector<int> nums1(nums.begin(),nums.end()-1);
    vector<int> nums2(nums.begin()+1,nums.end());
    return max(solve(nums1,0,dp1),solve(nums2,0,dp2));
}

int main()
{
    vector<int> nums = {1,2,3,1};
    int res = rob(nums);
    cout<<res<<endl;
}