#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr,int n,int idx)
{
    int l = (2*idx) + 1;
    int r = (2*idx) + 2;
    int largest = idx;
    if (l<n and arr[l]>arr[largest])
    {
        largest = l;
    }
    if (r<n and arr[r]>arr[largest])
    {
        largest = r;
    }
    if (largest!=idx)
    {
        swap(arr[idx],arr[largest]);
        heapify(arr,n,largest);
    }
}
void convertMinHeapToMaxHeap(vector<int>& arr)
{
    for (int i=arr.size()/2-1;i>=0;i--)
    {
        heapify(arr,arr.size(),i);
    }
}
int main()
{
    vector<int> arr = {3, 4, 8, 11, 13};
    convertMinHeapToMaxHeap(arr);
    for (auto x:arr)
    {
        cout<<x<<" ";
    }
}