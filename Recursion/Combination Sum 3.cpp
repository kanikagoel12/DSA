#include <bits/stdc++.h>
using namespace std;

void solve(int k,int n,set<int>& path,set<set<int>>& res){
    if(n==0 and k==0){
        res.insert(path);
        return;
    }
    if(k<0 or n<0){
        return ;
    }
    for(int i=1;i<=9;i++){
        if(path.find(i)==path.end()){
            path.insert(i);
            solve(k-1,n-i,path,res);
            path.erase(i);
        }
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    set<set<int>> temp;
    set<int> path;
    solve(k,n,path,temp);
    for(set<int> t:temp){
        vector<int> a(t.begin(),t.end());
        res.push_back(a);
    }
    return res;
}

int main()
{
    int k=3;
    int n=9;
    vector<vector<int>> res = combinationSum3(k,n);
    for(auto ele:res){
        for(auto ele1:ele){
            cout<<ele1<<" ";
        }
        cout<<endl;
    }
}