#include<bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int node;
    int time;
    Pair(int node,int time)
    {
        this->node = node;
        this->time = time;
    }
};
struct cmp
{
    bool operator()(Pair p1, Pair p2)
    {
        return p1.time > p2.time;
    }
};

vector<vector<Pair>> buildGraph(int n,vector<vector<int>>& edges)
{
    vector<vector<Pair>> adj(n+1);
    for (vector<int> edge:edges)
    {
        adj[edge[0]].push_back(Pair(edge[1],edge[2]));
    }
    return adj;
}
int networkDelayTime(vector<vector<int>>& times,int n,int k)
{
    int src=k;
    priority_queue<Pair,vector<Pair>,cmp> pq;
    vector<int> time(n+1,INT_MAX);
    time[src] = 0;
    pq.push({src,time[src]});
    vector<vector<Pair>> adj = buildGraph(n,times);

    while (!pq.empty())
    {
        int u = pq.top().node;
        int d = pq.top().time;
        pq.pop();

        if (time[u]<d) continue;

        for (auto nbr:adj[u])
        {
            int v = nbr.node;
            int t = nbr.time;

            if (time[u]+t<time[v])
            {
                time[v] = time[u]+t;
                pq.push({v,time[v]});
            }
        }
    }

    int minTime = -1;

    for (int i=1;i<=n;i++)
    {
        if (time[i] == INT_MAX) return -1;
        minTime = max(minTime,time[i]);
    }

    return minTime;
}

int main()
{
    vector<vector<int>> times= {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k=2;
    cout<<networkDelayTime(times,n,k);
}