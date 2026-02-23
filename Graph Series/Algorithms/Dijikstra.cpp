#include<bits/stdc++.h>
using namespace std;

vector<int> dijikstra(vector<vector<pair<int,int>>>& adj,int n,int src)
{
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({dist[src],src});

    while (!pq.empty())
    {
        pair<int,int> curr = pq.top();
        pq.pop();
        int u = curr.second;
        int d = curr.first;

        for (auto nbr:adj[u])
        {
            int v = nbr.first;
            int w = nbr.second;

            if (dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
vector<vector<pair<int,int>>> buildGraph(int n,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(n);
    for (vector<int> edge:edges)
    {
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }
    return adj;
}
int main()
{
    vector<vector<int>> edges = {{0,1,4},{1,4,6},{0,2,8},{2,3,2},{3,4,10}};
    int n = 5;
    vector<vector<pair<int,int>>> adj = buildGraph(n,edges);
    vector<int> dist = dijikstra(adj,n,0);
    for (int i=0;i<n;i++) cout<<dist[i]<<" ";
}