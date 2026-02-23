#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int k){
    int ws = 0;
    int cnt = 0;
    int n = nums.size();
    int res = 0;
    for(int we=0;we<n;we++){
        if(nums[we]%2 != 0){
            cnt++;
        }
        while(cnt>k){
            if(nums[ws]%2!=0){
                cnt--;
            }
            ws++;
        }
        res += we-ws+1;
    }
    return res;
}

int main()
{
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout<<solve(nums,k)-solve(nums,k-1);
}