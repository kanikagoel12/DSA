#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> freq;
    int ws = 0;
    int maxLen = 0;
    for(int we=0;we<s.length();we++){
        freq[s[we]]++;
        if(freq.size()<we-ws+1){
            freq[s[ws]]--;
            if(freq[s[ws]] == 0){
                freq.erase(s[ws]);
            }
            ws++;
        }
        maxLen = max(maxLen,we-ws+1);
    }
    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);
}