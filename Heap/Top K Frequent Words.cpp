#include<bits/stdc++.h>
using namespace std;

class word{
public:
    string wrd;
    int freq;
    word(string w,int f){
        wrd = w;
        freq = f;
    }
};
struct cmp{
    bool operator()(const auto& a,const auto& b){
        return (a.freq==b.freq)?a.wrd<=b.wrd:a.freq>b.freq;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string wrd:words){
            freq[wrd]++;
        }
        priority_queue<word,vector<word>,cmp> pq;
        for(auto x:freq){
            pq.push(word(x.first,x.second));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().wrd);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> res = Solution().topKFrequent(words,k);
    for (string ele:res)
    {
        cout<<ele<<" ";
    }
}