#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    int ans=0;

    for (int l=0;l<n;l++)
    {
        for (int r=l;r<n;r++)
        {
            vector<int> outside;
            vector<int> inside;
            int sum=0;
            for (int i=0;i<n;i++)
            {
                if (i>=l and i<=r)
                {
                    inside.push_back(arr[i]);
                    sum+=arr[i];
                }
                else
                {
                    outside.push_back(arr[i]);
                }
            }
            sort(inside.begin(),inside.end());
            sort(outside.begin(),outside.end(),greater<int>());

            int swaps = min(k,(int)min(inside.size(),outside.size()));

            for (int i=0;i<swaps;i++)
            {
                if (outside[i]>inside[i])
                {
                    sum+=outside[i]-inside[i];
                }
                else break;
            }

            ans = max(ans,sum);
        }
    }
    cout<<ans;
}