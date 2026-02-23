#include<bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findSet(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findSet(parent[u]);
    }
    void unionSet(int u,int v)
    {
        int p1 = findSet(u);
        int p2 = findSet(v);
        if (p1 == p2)
        {
            return;
        }
        if (rank[p1] == rank[p2])
        {
            parent[p2] = p1;
            rank[p1]++;
        }
        else if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else
        {
            parent[p1] = p2;
        }
    }
    bool isSameSet(int u,int v)
    {
        return findSet(u) == findSet(v);
    }
};
int KruskalMST(vector<vector<int>>& edges,int n)
{
    DSU dsu(n);
    int cost = 0;
    sort(edges.begin(),edges.end(),[](const auto& a,const auto& b)
    {
        return a[2] < b[2];
    });
    for (vector<int> edge:edges)
    {
        int u = edge[0];
        int v = edge[1];
        if (!dsu.isSameSet(u,v))
        {
            cost += edge[2];
            dsu.unionSet(u,v);
        }
    }
    return cost;
}
int main()
{
    vector<vector<int>> edges = {
        { 3, 5, 14 },
        { 1, 7, 11 },
        { 4, 5, 10 },
        { 4, 3, 9 },
        { 1, 2, 8 },
        { 0, 7, 8 },
        { 7, 8, 7 },
        { 2, 3, 7 },
        { 6, 8, 6 },
        { 2, 5, 4 },
        { 0, 1, 4 },
        { 5, 6, 2 },
        { 2, 8, 2 },
        { 6, 7, 1 }
    };
    cout<<KruskalMST(edges,9)<<endl;
}