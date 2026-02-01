#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char,int> mp;
    int ws = 0;
    int n = s.length();
    int maxFreq = 0;
    int maxLen = 0;

    for(int we=0;we<n;we++){
        mp[s[we]]++;
        maxFreq = max(maxFreq,mp[s[we]]);
        int replacable = (we-ws+1) - maxFreq;
        if(replacable>k){
            mp[s[ws]]--;
            if(mp[s[ws]] == 0){
                mp.erase(s[ws]);
            }
            ws++;
        }
        maxLen = max(maxLen,we-ws+1);
    }

    return maxLen;
}

int main()
{
    string s = "AABCDBB";
    int k = 2;
    cout<<characterReplacement(s,k);
}