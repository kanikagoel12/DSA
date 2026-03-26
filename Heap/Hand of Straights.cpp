#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize)
{
    int n = hand.size();
    if (n%groupSize != 0) return false;

    unordered_map<int,int> mp;
    sort(hand.begin(),hand.end());

    for (int i=0;i<n;i++)
    {
        mp[hand[i]]++;
    }

    for (int i=0;i<n;i++)
    {
        int num = hand[i];
        int grpEle = 0;
        if(mp.find(num)==mp.end()) continue;
        while (mp.find(num)!=mp.end())
        {
            mp[num]--;
            if (mp[num]==0) mp.erase(num);
            num++;
            grpEle++;
            if (grpEle==groupSize) break;
        }
        if (grpEle != groupSize) return false;
    }
    return true;
}

int main()
{
    vector<int> hands = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    bool res = isNStraightHand(hands,groupSize);
    cout<<res<<endl;
}