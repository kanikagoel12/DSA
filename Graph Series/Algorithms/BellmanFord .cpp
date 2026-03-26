#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> &edges,int n,int src)
{
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    for (int i=0;i<n;i++)
    {
        for (vector<int> edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u]!=INT_MAX && dist[u]+w<dist[v])
            {
                if (i==n-1)
                {
                    return {-1};
                }
                dist[v] = dist[u]+w;
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };
    int src = 0;
    vector<int> res = bellmanFord(edges,n,src);
    for (int ele:res)
    {
        cout<<ele<<" ";
    }
    return 0;
}