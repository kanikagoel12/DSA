#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    priority_queue<int> pq;
    int time = 0;
    //counting the frequency of each task
    for (char ch:tasks)
    {
        freq[ch]++;
    }
    //maintain a priority queue for the frequencies which is also the distinct tasks
    for (auto x:freq)
    {
        pq.push(x.second);
    }
    while (!pq.empty())
    {
        int cycle = n+1;
        vector<int> temp;
        int taskCnt = 0;
        while (cycle-->0 and !pq.empty())
        {
            if (pq.top()>1)
            {
                temp.push_back(pq.top()-1);
            }
            pq.pop();
            taskCnt++;
        }
        for (int x:temp)
        {
            pq.push(x);
        }
        time += taskCnt;
        if (!pq.empty()) time+=cycle+1;
    }
    return time;
}
int main()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<leastInterval(tasks,n);
}