#include <bits/stdc++.h>
using namespace std;
class Point
{
public:
    int x,y,dist;

    Point(int x,int y){
        this->x = x;
        this->y = y;
        dist = (x*x) + (y*y);
    }
};
vector<vector<int>> kclosest(vector<vector<int>>& points,int k)
{
    struct cmp
    {
        bool operator()(const Point& a,const Point& b){
        return a.dist < b.dist;
        }
    };
    vector<vector<int>> ans;
    priority_queue<Point,vector<Point>,cmp> pq;
    for (vector<int>& point:points)
    {
        int x = point[0];
        int y = point[1];
        pq.push(Point(x,y));
        if (pq.size()>k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back({pq.top().x,pq.top().y});
        pq.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    vector<vector<int>> ans = kclosest(points,k);
    for (vector<int>& point:ans)
    {
        cout<<point[0]<<" "<<point[1]<<endl;
    }
}