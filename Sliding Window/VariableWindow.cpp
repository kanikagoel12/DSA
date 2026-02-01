#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums,int target)
{
    int n = nums.size();
    int ws = 0;
    int sum  = 0;
    int minLen = INT_MAX;

    for (int we=0;we<n;we++)
    {
        sum += nums[we];
        while (sum>=target)
        {
            minLen = min(minLen,we-ws+1);
            sum -= nums[ws++];
        }
    }
    return  minLen!=INT_MAX?minLen:0;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<subarraySum(nums,target);
}