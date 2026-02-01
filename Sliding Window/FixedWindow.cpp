#include<bits/stdc++.h>
using namespace std;

bool subarraySum(vector<int>& nums,int k,int target)
{
    int n = nums.size();
    int ws = 0;
    int sum  = 0;

    for (int we=0;we<n;we++)
    {
        sum += nums[we];
        if (we>=k-1)
        {
            if (sum==target) return true;
            sum -= nums[ws++];
        }
    }
    return  false;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int k = 3;
    int target = 7;
    cout<<subarraySum(nums,k,target);
}