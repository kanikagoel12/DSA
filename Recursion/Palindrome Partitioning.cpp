#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
}

void solve(string s,int idx,vector<vector<string>>& res,vector<string>& temp){
        if(idx==s.length()){
            res.push_back(temp);
        }

        for(int i=idx;i<s.length();i++){
            string t=s.substr(idx,(i-idx+1));
            //cout<<t<<" "<<i<<endl;
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(s,i+1,res,temp);
                temp.pop_back();
            }
        }

    }

vector<vector<string>> partition(string s) {
    vector<string> temp;
    vector<vector<string>> res;
    solve(s,0,res,temp);
    return res;
}

int main()
{
    vector<vector<string>> res;
    vector<string> temp;
    string s="aab";
    res=partition(s);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}