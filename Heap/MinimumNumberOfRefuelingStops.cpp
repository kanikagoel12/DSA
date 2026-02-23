#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int maxPos = startFuel;
    int i=0;
    int stops = 0;
    while(maxPos<target){
        while(i<stations.size() and stations[i][0]<=maxPos){
            pq.push(stations[i][1]);
            i++;
        }
        if(pq.empty()) return -1;
        maxPos += pq.top();
        pq.pop();
        stops++;
    }
    return stops;
}

int main()
{
    vector<vector<int>> stations = {{10,15},{20,25}};
    int target = 55;
    cout<<minRefuelStops(target,10,stations);
}