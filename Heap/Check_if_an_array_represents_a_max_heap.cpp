#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Your code goes here
    for(int i=0;i<n;i++){
        int leftIdx = (2*i)+1;
        int rightIdx = (2*i)+2;
        if(leftIdx<n and arr[leftIdx]>arr[i]){
            return false;
        }
        if(rightIdx<n and arr[rightIdx]>arr[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {9, 15, 10, 7, 12, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << isMaxHeap(arr, n);
}