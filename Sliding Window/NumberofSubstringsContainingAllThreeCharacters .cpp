#include<bits/stdc++.h>
using namespace std;

int solve(string s,int k){
     unordered_map<char,int> mp;
     int cnt = 0;
     int ws=0;
     for(int we=0;we<s.length();we++){
          mp[s[we]]++;
          while(mp.size()>k){
               mp[s[ws]]--;
               if(mp[s[ws]]==0){
                    mp.erase(s[ws]);
               }
               ws++;
          }
          cnt+=we-ws+1;
     }
     return cnt;
}

int numberOfSubstrings(string s) {
     return solve(s,3)-solve(s,2);
}

int main()
{
     string s = "abcabc";
     cout<<numberOfSubstrings(s);
}