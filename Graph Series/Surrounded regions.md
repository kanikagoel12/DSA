# Rotting Oranges 🍊

🔗 **LeetCode Problem Link:**  
https://leetcode.com/problems/surrounded-regions/

## 🧠 Approach

- The regions that **should NOT be flipped** are the `'O'` cells that are connected to the **boundary** of the board.
- Traverse all boundary cells (first row, last row, first column, last column).
- Whenever a boundary cell contains `'O'`, perform **BFS** from that cell.
- During BFS, mark all connected `'O'` cells as a temporary character (for example `'Y'`) to indicate they are **safe**.
- After BFS traversal:
    - Convert all remaining `'O'` cells (not connected to boundary) into `'X'`.
    - Convert all temporary `'Y'` cells back to `'O'`.

This ensures only the **surrounded regions** are captured.

---

## C++ Solution:

```cpp
class Cell{
    public:
    int row,col;
    Cell(int r,int c){
        row = r;
        col = c;
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
    void solve(vector<vector<char>>& board) {
        queue<Cell> q;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][n-1] == 'O'){
                q.push(Cell(i,n-1));
                board[i][n-1] = 'Y';
            }
            if(board[i][0] == 'O'){
                q.push(Cell(i,0));
                board[i][0] = 'Y';
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i] == 'O'){
                q.push(Cell(m-1,i));
                board[m-1][i] = 'Y';
            }
            if(board[0][i] == 'O'){
                q.push(Cell(0,i));
                board[0][i] = 'Y';
            }
        }
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}}; 
        while(!q.empty()){
            Cell curr = q.front();
            q.pop();
            for(auto drs:directions){
                int r = curr.row + drs[0];
                int c = curr.col + drs[1];
                if(isPossible(r,c,m,n) and board[r][c] == 'O'){
                    q.push(Cell(r,c));
                    board[r][c] = 'Y';
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

## Java Solution:

```java
import java.util.*;

class Cell {
    int row, col;

    Cell(int r, int c) {
        row = r;
        col = c;
    }
}

class Solution {

    private boolean isPossible(int i, int j, int r, int c) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;

        Queue<Cell> q = new LinkedList<>();

        // Traverse first and last column
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                q.offer(new Cell(i, n - 1));
                board[i][n - 1] = 'Y';
            }
            if (board[i][0] == 'O') {
                q.offer(new Cell(i, 0));
                board[i][0] = 'Y';
            }
        }

        // Traverse first and last row
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O') {
                q.offer(new Cell(m - 1, j));
                board[m - 1][j] = 'Y';
            }
            if (board[0][j] == 'O') {
                q.offer(new Cell(0, j));
                board[0][j] = 'Y';
            }
        }

        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.isEmpty()) {
            Cell curr = q.poll();

            for (int[] drs : directions) {
                int r = curr.row + drs[0];
                int c = curr.col + drs[1];

                if (isPossible(r, c, m, n) && board[r][c] == 'O') {
                    q.offer(new Cell(r, c));
                    board[r][c] = 'Y';
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
}

```
### Time Complexity
- **O(m × n)**  
  Each cell of the board is visited at most once during the BFS traversal and the final conversion step.

### Space Complexity
- **O(m × n)**  
  In the worst case, the BFS queue may store all cells of the board.