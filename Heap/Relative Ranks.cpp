#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& scores) {
    priority_queue<int> pq;
    vector<string> res;
    for(int score:scores){
        pq.push(score);
    }
    int rank = 1;
    unordered_map<int,int> mp;
    while(!pq.empty()){
        mp[pq.top()] = rank;
        rank++;
        pq.pop();
    }
    for(int score:scores){
        if(mp[score]==1){
            res.push_back("Gold Medal");
        }
        else if(mp[score]==2){
            res.push_back("Silver Medal");
        }
        else if(mp[score]==3){
            res.push_back("Bronze Medal");
        }
        else{
            res.push_back(to_string(mp[score]));
        }
    }
    return res;
}

int main()
{
    vector<int> scores = {5,4,3,2,1};
    vector<string> res = findRelativeRanks(scores);
    for(string ele:res) cout<<ele<<" ";
}