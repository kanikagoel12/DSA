
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> parent;
public:
    UnionFind(int n)
    {
        for (int i=0;i<n;i++) parent.push_back(i);
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }
    void unite(int u,int v)
    {
        int pu = find(u);
        int pv = find(v);
        parent[pu] = pv;
    }
};
int main()
{
    int size = 7;
    UnionFind uf(size);
    uf.unite(1,2);
    uf.unite(3,4);
    uf.unite(1,4);
    uf.unite(5,6);
    bool isSameSet1 = uf.find(4)==uf.find(6);
    uf.unite(6,4);
    bool isSameSet2 = uf.find(4)==uf.find(6);
    cout<<isSameSet1<<" "<<isSameSet2<<endl;
    return 0;
}