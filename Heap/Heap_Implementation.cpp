#include<bits/stdc++.h>
using namespace std;

class minHeap
{
public:
    int size;
    vector<int> arr;
    int index = -1;
    minHeap(int n)
    {
        size = n;
        arr.resize(n);
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    int getLeftChild(int i)
    {
        return (2*i)+1;
    }
    int getRightChild(int i)
    {
        return (2*i)+2;
    }
    void insert(int x)
    {
        if (index == size-1)
        {
            cout<<"Heap is full"<<endl;
            return;
        }
        index++;
        arr[index] = x;
        int k = index;

        while (k!=0 and arr[k]<arr[parent(k)])
        {
            swap(arr[k],arr[parent(k)]);
            k = parent(k);
        }
    }
    void heapify(int i)
    {
        int l = getLeftChild(i);
        int r = getRightChild(i);
        int smallest = i;
        if (l<size and arr[l]<arr[smallest]) smallest = l;
        if (r<size and arr[r]<arr[smallest]) smallest = r;
        if (smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }
    }
    int getMin()
    {
        if (size>0) return arr[0];
        return INT_MAX;
    }
    void printHeap()
    {
        int n = index;
        int levels = log2(n) + 1;
        int maxWidth = pow(2, levels);

        int index = 0;

        for (int i = 0; i < levels; i++) {
            int nodes = pow(2, i);
            int spaces = maxWidth / pow(2, i + 1);

            for (int s = 0; s < spaces; s++) cout << " ";

            for (int j = 0; j < nodes && index < n; j++) {
                cout << arr[index++];
                for (int s = 0; s < spaces * 2; s++) cout << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    minHeap h(10);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);
    h.printHeap();
}