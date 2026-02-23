#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char,int> freq;
    for (char ch:s)
    {
        freq[ch]++;
    }
    priority_queue<pair<int,char>> pq;
    for (auto ele:freq)
    {
        pq.push(make_pair(ele.second,ele.first));
    }
    string res;
    while (!pq.empty())
    {
        int freq = pq.top().first;
        while (freq-->0)
        {
            res.push_back(pq.top().second);
        }
        pq.pop();
    }
    return res;
}

int main()
{
    string s = "tree";
    cout<<frequencySort(s);
}