#include<bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int node;
    int dist;
    Pair(int node,int dist)
    {
        this->node = node;
        this->dist = dist;
    }
};
struct cmp
{
    bool operator()(Pair p1, Pair p2)
    {
        return p1.dist > p2.dist;
    }
};

vector<vector<Pair>> buildGraph(int n,vector<vector<int>>& edges)
{
    vector<vector<Pair>> adj(n);
    for (vector<int> edge:edges)
    {
        adj[edge[0]].push_back(Pair(edge[1],edge[2]));
        adj[edge[1]].push_back(Pair(edge[0],edge[2]));
    }
    return adj;
}
int countRoads(vector<vector<int>>& roads,int n)
{
    int src=0;
    int dest=n-1;
    priority_queue<Pair,vector<Pair>,cmp> pq;
    vector<int> dist(n,INT_MAX);
    vector<int> ways(n,0);
    dist[src] = 0;
    ways[src]=1;
    pq.push({src,dist[src]});
    vector<vector<Pair>> adj = buildGraph(n,roads);

    while (!pq.empty())
    {
        int u = pq.top().node;
        int d = pq.top().dist;
        pq.pop();

        if (dist[u]<d) continue;

        for (auto nbr:adj[u])
        {
            int v = nbr.node;
            int wt = nbr.dist;

            if (dist[u]+wt<dist[v])
            {
                dist[v] = dist[u]+wt;
                pq.push({v,dist[v]});
                ways[v] = ways[u];
            }
            else if (dist[u]+wt == dist[v])
            {
                ways[v] += ways[u];
            }
        }
    }

    return ways[dest];
}

int main()
{
    vector<vector<int>> roads =
{{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int n = 7;
    cout<<countRoads(roads,n);
}