#include <bits/stdc++.h>
using namespace std;

//          BRUTE FORCE APPROACH -> O(N^2)

//int main()
//{
//    int n;
//    cin>>n;
//    vector<int> arr(n);
//    for (int i=0;i<n;i++) cin>>arr[i];
//
//    int q;
//    cin>>q;
//    vector<vector<int>> queries(q,vector<int>(3));
//    for (int i=0;i<q;i++)
//    {
//        cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
//    }
//    int res=0;
//    for (auto query:queries)
//    {
//        int ch=query[0];
//        int l = query[1];
//        int r = query[2];
//        if (ch==1)
//        {
//            for (int i=l;i<=r;i++)
//            {
//                arr[i] = (i-l+1)*arr[l];
//            }
//        }
//        else
//        {
//            int sum=0;
//            for (int i=l;i<=r;i++)
//            {
//                sum+=arr[i];
//            }
//            res+=sum;
//        }
//    }
//    cout<<res;
//}


int main()
{
    int n;
    cin>>n;

    vector<long long> A(n);

    for (int i=0;i<n;i++) cin>>A[i];

    int q;
    cin>>q;

    vector<long long> B(n+1,0);
    vector<long long> C(n+1,0);

    while (q--)
    {
        int l,r,x,y;
        cin>>l>>r>>x>>y;

        long long constant = x - 1LL*l*y;

        B[l] += constant;
        B[r+1] -= constant;

        C[l] += y;
        C[r+1] -= y;
    }

    for (int i=1;i<n;i++)
    {
        B[i] += B[i-1];
        C[i] += C[i-1];
    }

    long long sum = 0;
    const long long MOD = 1e9+7;

    for (int i=0;i<n;i++)
    {
        A[i] = B[i] + C[i]*i;
        sum = (sum + A[i]) % MOD;
    }

    cout<<sum<<endl;

    return 0;
}