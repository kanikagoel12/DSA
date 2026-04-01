#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector<string>& res,string temp,int open,int close,int n){
    if(close==n){
        res.push_back(temp);
    }
    if(open<n){
        temp.push_back('(');
        solve(res,temp,open+1,close,n);
        temp.pop_back();
    }
    if(open>close){
        temp.push_back(')');
        solve(res,temp,open,close+1,n);
    }

}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    int open = 0;
    int close = 0;
    string temp = "";
    solve(res,temp,open,close,n);
    return res;
}

int main()
{
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for(string ele:res)
    {
        cout<<ele<<" ";
    }
}