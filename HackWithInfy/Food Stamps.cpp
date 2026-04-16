#include <bits/stdc++.h>
using namespace std;

long long count_ge(long long x,vector<long long> v,vector<long long> d,long long m)
{
    long long cnt = 0;
    int n=v.size();

    for (int i=0;i<n;i++)
    {
        if (v[i]>=x)
        {
            cnt+=(v[i]-x)/d[i] + 1;
            if (cnt>=m) return cnt;
        }
    }

    return cnt;
}

int main()
{
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> v(n);
    vector<long long> d(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>d[i];
    }

    long long low=1;
    long long high=n-1;
    long long X=0;

    while (low<=high)
    {
        long long mid = low+(high-low)/2;

        if (count_ge(mid,v,d,m)>=m)
        {
            X=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    long long total=0;
    long long used=0;

    for (int i=0;i<n;i++)
    {
        if (v[i]>=X)
        {
            long long t = (v[i]-X)/d[i] + 1;
            long long last = v[i] - (t-1)*d[i];
            total+=t*(v[i]+last)/2;
            used+=t;
        }
    }

    total-=(used-m)*X;
    cout<<total<<endl;
}