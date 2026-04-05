#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> buildGraph(vector<vector<int>>& edges,int V){
    vector<vector<int>> adj(V);
    for(vector<int> edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    return adj;
}
bool isSafe(int node,vector<int>& color,vector<vector<int>>& adj,int n,int col){
    for(auto x:adj[node]){
        if(color[x]==col){
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<int>& color,int m,int V,vector<vector<int>>& adj){
    if(node==V) return true;

    for(int i=1;i<=m;i++){
        if(isSafe(node,color,adj,V,i)){
            color[node]=i;
            if(solve(node+1,color,m,V,adj)){
                return true;
            }
            color[node]=-1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    // code here
    vector<int> color(v,-1);
    vector<vector<int>> adj = buildGraph(edges,v);
    if(solve(0,color,m,v,adj)) return true;
    return false;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1},
        {1, 3},
        {2, 3},
        {3, 0},
        {0, 2}
    };
    int V=4;
    int m=3;
    bool ans = graphColoring(V,edges,m);
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}