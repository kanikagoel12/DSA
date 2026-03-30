#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& ans,vector<int> output,vector<int> nums,int index){
    if(index>=nums.size())
    {
        ans.push_back(output);
        return;
    }
    //exclude
    solve(ans,output,nums,index+1);
    //include
    output.push_back(nums[index]);
    solve(ans,output,nums,index+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(ans,output,nums,index);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsets(nums);
    for (auto ele:ans)
    {
        for (auto ele1:ele)
        {
            cout<<ele1<<" ";
        }
        cout<<endl;
    }
}