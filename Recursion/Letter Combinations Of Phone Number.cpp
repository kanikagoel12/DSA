#include <bits/stdc++.h>
using namespace std;


void solve(unordered_map<int,string> mp,string digits,int idx,string& path,vector<string>& res){
    if(idx==digits.length()){
        res.push_back(path);
        return;
    }

    for(char x:mp[digits[idx]-'0']){
        path.push_back(x);
        solve(mp,digits,idx+1,path,res);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    unordered_map<int,string> mp;
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";
    vector<string> res;
    string path;

    solve(mp,digits,0,path,res);

    return res;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for(string ele:ans)
    {
        cout<<ele<<" ";
    }
}