#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& candidates, int target,int idx,vector<int>& path,vector<vector<int>>& res){

    if(target==0){
        res.push_back(path);
        return;
    }

    for(int i=idx;i<candidates.size();i++){
        if(i>idx and candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;

        path.push_back(candidates[i]);
        target-=candidates[i];
        solve(candidates,target,i+1,path,res);
        target+=candidates[i];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //cout<<candidates.size()<<endl;
    set<vector<int>> res;
    vector<vector<int>> ans;
    vector<int> path;
    sort(candidates.begin(),candidates.end());
    solve(candidates,target,0,path,ans);
    return ans;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates,target);
    for (auto x:ans)
    {
        for (auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}