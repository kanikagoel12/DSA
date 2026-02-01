#include<bits/stdc++.h>
using namespace std;

class DSURank
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSURank(int n)
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
        return findSet(parent[u]);
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
    void printParentandRank()
    {
        cout<<"Parent"<<endl;
        for (int i=0;i<parent.size();i++) cout<<parent[i];
        cout<<endl<<"Rank"<<endl;
        for (int i=0;i<rank.size();i++) cout<<rank[i];
    }
};
int main()
{
    DSURank dsu(9);
    dsu.unionSet(0, 1);
    dsu.unionSet(0, 2);
    dsu.unionSet(1, 2);
    dsu.unionSet(1, 3);
    dsu.unionSet(2, 3);
    dsu.unionSet(3, 4);
    dsu.unionSet(5, 6);
    dsu.unionSet(7, 8);
    dsu.unionSet(5, 7);
    dsu.unionSet(4, 6);

    dsu.printParentandRank();
}