#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];

    unordered_map<int,int> mp;
    int ws=0;
    int sum=0;
    int maxSum=0;
    for (int we=0;we<n;we++)
    {
        mp[arr[we]]++;
        sum+=arr[we];
        while (mp.size()>k)
        {
            mp[arr[ws]]--;
            sum-=arr[ws];
            if (mp[arr[ws]]==0) mp.erase(arr[ws]);
            ws++;
        }
        maxSum = max(maxSum,sum);
        if(sum < 0)
        {
            mp.clear();
            sum = 0;
            ws = we + 1;
        }
    }

    cout<<maxSum<<endl;
}