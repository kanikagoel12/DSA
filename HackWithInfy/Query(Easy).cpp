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

