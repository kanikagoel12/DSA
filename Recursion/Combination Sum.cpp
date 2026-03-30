#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& candidates, int target,int idx,vector<int>& path,vector<vector<int>>& res){
    if(target==0 and idx==candidates.size()){
        res.push_back(path);
        return;
    }
    if(target<0 or idx>=candidates.size()){
        return;
    }

    solve(candidates,target,idx+1,path,res);
    path.push_back(candidates[idx]);
    solve(candidates,target-candidates[idx],idx,path,res);
    path.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    solve(candidates,target,0,path,res);
    return res;
}

int main()
{
   vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates,target);
    for(auto ele:res){
        for(auto ele1:ele){
            cout<<ele1<<" ";
        }
        cout<<endl;
    }
}