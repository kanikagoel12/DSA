#include<bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int node;
    int cost;
    int stop;
    Pair(int node,int cost)
    {
        this->node = node;
        this->cost = cost;
    }
    Pair(int node,int cost,int stop)
    {
        this->node = node;
        this->cost = cost;
        this->stop = stop;
    }
};
struct cmp
{
    bool operator()(Pair p1, Pair p2)
    {
        return p1.cost > p2.cost;
    }
};

vector<vector<Pair>> buildGraph(int n,vector<vector<int>>& edges)
{
    vector<vector<Pair>> adj(n);
    for (vector<int> edge:edges)
    {
        adj[edge[0]].push_back(Pair(edge[1],edge[2]));
    }
    return adj;
}
int findCheapestPrice(vector<vector<int>>& flights,int n,int src,int dest,int k)
{
    priority_queue<Pair,vector<Pair>,cmp> pq;
    vector<int> cost(n,INT_MAX);
    vector<int> stops(n,0);
    cost[src] = 0;
    stops[src]=0;
    pq.push({src,cost[src],0});
    vector<vector<Pair>> adj = buildGraph(n,flights);

    while (!pq.empty())
    {
        int u = pq.top().node;
        int d = pq.top().cost;
        int s = pq.top().stop;
        pq.pop();

        if (u==dest) return d;

        if (s==k+1) continue;

        for (auto nbr:adj[u])
        {
            int v = nbr.node;
            int cst = nbr.cost;
            int stop = nbr.stop;

            if (cost[u]+cst<cost[v])
            {
                cost[v] = cost[u]+cst;
                stops[v] = stops[u] + 1;
                pq.push({v,cost[v],stops[v]});
            }
            else if (stops[u]+1<stops[v])
            {
                pq.push({v,cost[v],stops[v]});
            }
        }
    }

    return stops[dest];
}

int main()
{
    vector<vector<int>> flights =
   {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4;
    cout<<findCheapestPrice(flights,n,0,3,1);
}