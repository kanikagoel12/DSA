# Rotting Oranges 🍊

🔗 **LeetCode Problem Link:**  
https://leetcode.com/problems/rotting-oranges/description/

## 🧠 Approach
- Use multi-source BFS
- Push all initially rotten oranges into the queue
- Spread rot to adjacent fresh oranges level by level
- Track time using BFS depth
- If any fresh orange remains, return -1


## C++ Solution:

```cpp
class orangeInfo{
    public:
    int row,col,time;
    orangeInfo(int r,int c,int t){
        row = r;
        col = c;
        time = t;
    }
};
class Solution {
private:
    bool isPossible(int i,int j,int r,int c){
        if(i>=0 and i<r and j>=0 and j<c){
            return true;
        }
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<orangeInfo> q;
       int m = grid.size();
       int n = grid[0].size();
       
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                q.push(orangeInfo(i,j,0));
            }
        }
       }
       
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        
       while(!q.empty()){
            orangeInfo curr = q.front();
            q.pop();
            for(auto drs:directions){
                int r = curr.row + drs[0];
                int c = curr.col + drs[1];
                int t = curr.time;
                if(isPossible(r,c,m,n) and grid[r][c] == 1){
                    q.push(orangeInfo(r,c,t+1));
                    grid[r][c] = 2;
                    res = max(res,t+1);
                }
            }
       }
       
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
               return -1;
            }
        }
       } 
       
       return res;
    }
};
```

## Java Solution:

```java
import java.util.*;

class OrangeInfo {
    int row, col, time;

    OrangeInfo(int r, int c, int t) {
        row = r;
        col = c;
        time = t;
    }
}

class Solution {

    private boolean isPossible(int i, int j, int r, int c) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    public int orangesRotting(int[][] grid) {
        Queue<OrangeInfo> q = new LinkedList<>();

        int m = grid.length;
        int n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new OrangeInfo(i, j, 0));
                }
            }
        }

        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;
        
        while (!q.isEmpty()) {
            OrangeInfo curr = q.poll();

            for (int[] drs : directions) {
                int r = curr.row + drs[0];
                int c = curr.col + drs[1];
                int t = curr.time;

                if (isPossible(r, c, m, n) && grid[r][c] == 1) {
                    q.offer(new OrangeInfo(r, c, t + 1));
                    grid[r][c] = 2;
                    res = Math.max(res, t + 1);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return res;
    }
}
```
## ⏱ Time and Space Complexity

### Time Complexity
- **O(m × n)**  
  Each cell of the grid is visited at most once during the BFS traversal.

### Space Complexity
- **O(m × n)**  
  Queue can store all cells in the worst case, and the grid itself is used for state tracking.
