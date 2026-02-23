#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int ws = 0;
    int sum  = 0;
    int n = nums.size();
    int maxLen = 0;
    for(int we=0;we<n;we++){
        sum+=nums[we];
        int flip = (we-ws+1)-sum;
        while(flip>k){
            sum -= nums[ws];
            ws++;
            flip = (we-ws+1)-sum;
        }
        maxLen = max(maxLen,we-ws+1);
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<longestOnes(nums,k);
}