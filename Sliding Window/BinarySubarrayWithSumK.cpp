#include<bits/stdc++.h>
using namespace std;

int binarySubarraySum(vector<int>& nums,int k)
{
    int n = nums.size();
    int ws = 0;
    int sum = 0;
    int cnt = 0;

    for (int we=0;we<n;we++)
    {
        sum += nums[we];
        while (sum>k)
        {
            sum -= nums[ws];
            ws++;
        }
        cnt += we-ws+1;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1,0,1,0,1};
    int k = 2;
    cout<<binarySubarraySum(nums,k)<<" "<<binarySubarraySum(nums,k-1);
}