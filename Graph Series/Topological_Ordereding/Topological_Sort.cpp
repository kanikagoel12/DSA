//
// Created by Dell on 1/24/2026.
//

#include "Topological_Sort.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj)
{
    int n = adj.size();
    vector<int> indegree(n,0);
    queue<int> q;
    vector<int> ans;
    //computing indegree
    for (vector<int> v:adj)
    {
        for (int nbr:v)
            indegree[nbr]++;
    }
    //initialising the src node
    for (int i=0;i<n;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    //Kahn's Algorithm
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);
        for (int nbr:adj[currNode])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}
void adjacencyList(vector<vector<int>>& edges,vector<vector<int>>& adj)
{
    for (vector<int> edge:edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
}
int main()
{
    cout<<"Topological Sorting"<<endl;
    int n = 2;
    vector<vector<int>> adj(n);
    //vector<vector<int>> edges = {{4,0},{4,3},{0,1},{0,2},{1,2},{3,0}};
    vector<vector<int>> edges = {{0,1},{1,0}};
    adjacencyList(edges,adj);

    vector<int> topoSort = topologicalSort(adj);
    for (int i:topoSort) cout<<i<<" ";
    return 0;
}