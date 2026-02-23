#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        int ws = 0;
        int n = s.length();
        int maxLen = -1;


        for(int we=0;we<n;we++){
            mp[s[we]]++;
            int distinct = mp.size();
            if(distinct>k){
               mp[s[ws]]--;
               if(mp[s[ws]] == 0){
                   mp.erase(s[ws]);
               }
               ws++;
            }
            if(distinct == k){
                maxLen = max(maxLen,we-ws+1);
            }
        }

        return maxLen;
}

int main()
{
    string s = "aabacbebebe";
    int k = 3;
    cout<<longestKSubstr(s,k);
}