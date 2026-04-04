#include<bits/stdc++.h>
using namespace std;

bool solve(string &s, vector<string> &dictionary,int idx,string newStr){
    if(newStr==s) return true;
    if(s.length()<newStr.length()) return false;
    bool ans = false;
    int n = dictionary.size();
    for(int i=0;i<n;i++){
        ans=ans or solve(s,dictionary,i,newStr+dictionary[i]);
    }
    return ans;
}
bool wordBreak(string &s, vector<string> &dictionary) {
    // code here
    string newStr="";
    return solve(s,dictionary,0,newStr);
}

int main()
{
    string s= "ilovecoding";
    vector<string> dictionary = {"apple","banana","banana","i","code","love","coding"};
    cout<<wordBreak(s,dictionary);
    return 0;
}