#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    priority_queue<int> pq;
    for (int stone:stones)
    {
        pq.push(stone);
    }
    while (pq.size()>1)
    {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        pq.push(abs(x-y));
    }
    return pq.top();
}

int main()
{
    vector<int> stones = {2,7,4,1,8,1};
    cout<<lastStoneWeight(stones);
}