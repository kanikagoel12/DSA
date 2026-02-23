#include <bits/stdc++.h>
using namespace std;

string isKSortedArray(int arr[], int n, int k) {
     // code here.
     unordered_map<int,int> idx;
     priority_queue<int> pq;
     for(int i=0;i<n;i++){
         idx[arr[i]] = i;
         pq.push(arr[i]);
     }
     int in = n-1;
     while(!pq.empty()){
         //cout<<idx[pq.top()]<<" "<<in<<endl;
         if(abs(in-idx[pq.top()])>k){
             return "No";
         }
         in--;
         pq.pop();
     }
     return "Yes";
 }

int main()
{
    vector<int> arr = {3,2,1,5,6, 4};
    int k = 2;
    cout<<isKSortedArray(arr.data(),arr.size(),k);
}