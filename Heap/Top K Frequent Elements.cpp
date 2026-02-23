#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int,int> freq;
    for (int num:nums)
    {
        freq[num]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (auto ele:freq)
    {
        pq.push(make_pair(ele.second,ele.first));
        if (pq.size()>k)
        {
            pq.pop();
        }
    }
    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main()
{
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    vector<int> res = topKFrequent(nums,k);
    for (int ele:res)
    {
        cout<<ele<<" ";
    }
}