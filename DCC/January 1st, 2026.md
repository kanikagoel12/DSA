# Plus One 

🔗 **LeetCode Problem Link:**  
https://leetcode.com/problems/plus-one/?envType=daily-question&envId=2026-01-01

## 🧠 Approach
- digits.size() - 1 to iterate from the last digit.
  - If the sum of the current digit and carry is less than 10
  - Else,
  - carry = (sum of the current digit and carry)/10
  - current digit = (sum of the current digit and carry)%10
- If carry is not 0,
- digits.insert(digits.begin(),carry);

# C++ Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            if(digits[i]+carry<=9){
                digits[i] = digits[i]+carry;
                return digits;
            }
            else{
                carry =  (digits[i]+carry)/10;
                digits[i] = (digits[i]+carry)%10;
            }
        }
        if(carry!=0) digits.insert(digits.begin(),carry);
        return digits;
    }
};
```

## ⏱ Time and Space Complexity

### Time Complexity
- **O(N)**

  Where N is the length of the given vector.

### Space Complexity
- **O(1)**

  We only use constant space.




# Intersection Point in Y-Shapped Linked Lists

🔗 **GeeksForGeeks Problem Link:**  
https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

## 🧠 Approach
- Use a set to store the visited nodes.
- If the current node is already visited,
- return it.
- Else,
- move to the next node.

# C++ Solution

```cpp
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        set<Node*> visited;
        while(head1!=NULL){
            visited.insert(head1);
            head1=head1->next;
        }
        while(head2!=NULL){
            if(visited.find(head2)!=visited.end()){
                return head2;
            }
            head2=head2->next;
        }
        return NULL;
    }
};
```

## ⏱ Time and Space Complexity

### Time Complexity
- **O(M+N)**

  The algorithm traverses the first list once (m nodes) inserting each node into a hash set, then traverses the second list once (n nodes) checking membership. Each operation on the set is O(1) on average, giving a total of O(m + n) time.

### Space Complexity
- **O(M)**

  A hash set stores a reference to every node of the first list, requiring space proportional to the length of that list, i.e., O(m). No additional space is used beyond the set.