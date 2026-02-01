#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    unordered_map<char,int> mp1;
    for (char ch:s1)
    {
        mp1[ch]++;
    }
    unordered_map<char,int> mp2;
    int ws = 0;
    for (int we=0;we<s2.length();we++)
    {
        mp2[s2[we]]++;
        if (we>=s1.length()-1)
        {
            if (mp1==mp2) return true;
            mp2[s2[ws]]--;
            if (mp2[s2[ws]]==0)
            {
                mp2.erase(s2[ws]);
            }
            ws++;
        }
    }
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidboaooo";
    bool res = checkInclusion(s1,s2);
    cout<<res<<endl;
}