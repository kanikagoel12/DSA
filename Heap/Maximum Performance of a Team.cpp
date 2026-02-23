#include<bits/stdc++.h>
using namespace std;

class Engineer{
public:
    int speed;
    int efficiency;
    Engineer(int s,int e){
        speed = s;
        efficiency = e;
    }
};
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    int MOD = 1000000007;
    vector<Engineer> engineers;
    for(int i=0;i<n;i++){
        engineers.push_back(Engineer(speed[i],efficiency[i]));
    }
    sort(engineers.begin(),engineers.end(),[](const auto& a,const auto& b){
        return a.efficiency>b.efficiency;
    });
    long long maxPer = 0;
    long long sum = 0;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(Engineer en:engineers){
        int s = en.speed;
        int e = en.efficiency;
        sum += s;
        minHeap.push(s);
        long long currPer = sum*e;
        maxPer = max(maxPer,currPer);
        if(minHeap.size()==k){
            sum-=minHeap.top();
            minHeap.pop();
        }
    }
    return maxPer%MOD;
}
int main()
{
    vector<int> speed = {2,10,3,1,5,8};
    vector<int> efficiency = {5,4,3,9,7,2};
    int k = 2;
    cout<<maxPerformance(speed.size(),speed,efficiency,k);
}