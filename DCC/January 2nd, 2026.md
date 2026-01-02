# N-Repeated Element in Size 2N Array

🔗 **LeetCode Problem Link**
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02

## 🧠 Approach
- Iterate through the array from the end.
- If the current element is not equal to the previous element,
- return it.
- Else,
- move to the next element.

# C++ Solution

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=2) return nums[i];
        }
        return 0;
    }
};
```

## ⏱ Time and Space Complexity

### Time Complexity
- **O(N)**

  The algorithm iterates through the array once, performing O(1) average‑time operations (hash map insertion and lookup) for each element, resulting in linear time O(n).

### Space Complexity
- **O(N)**

  In the worst case, all elements are distinct, so the unordered_map stores n entries, requiring O(n) additional space.




# Sort 0s, 1s and 2s

🔗 **GeeksForGeeks Problem Link:**  
https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

## 🧠 Approach
- Create a hash set to store the elements of the array.
- Iterate through the array and insert each element into the hash set.

# C++ Solution

```cpp
/*
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) zeros++;
            else if(arr[i]==1) ones++;
            else twos++;
        }
        
        for(int i=0;i<zeros;i++) arr[i] = 0;
        for(int i=zeros;i<ones+zeros;i++) arr[i] = 1;
        for(int i=ones+zeros;i<twos+ones+zeros;i++) arr[i] = 2;
    }
};
```

## ⏱ Time and Space Complexity

### Time Complexity
- **O(N)**

  The algorithm makes two linear passes over the array: one to count the occurrences of 0, 1, and 2, and another to rewrite the array based on those counts. Each pass processes each element once, giving a total time proportional to the number of elements, i.e., O(n).

### Space Complexity
- **O(1)**

  Only a few integer counters (zeros, ones, twos) and loop indices are used regardless of input size. No additional data structures proportional to n are allocated, resulting in constant auxiliary space, O(1).