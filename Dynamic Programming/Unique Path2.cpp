#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1,0},{0,1}};
bool isValid(int i,int j,int m,int n){
    if(i>=m or i<0 or j>=n or j<0){
        return false;
    }
    return true;
}
int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i==m-1 and j==n-1){
        return 1;
    }
    if(i>=m or j>=n){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;

    for(vector<int> dir:directions){
        int x = i+dir[0];
        int y = j+dir[1];
        if(isValid(x,y,m,n) and obstacleGrid[x][y]==0){
            ans+=solve(obstacleGrid,x,y,m,n,dp);
        }
    }

    return dp[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]==1) return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(obstacleGrid,0,0,m,n,dp);
}

int solve(vector<vector<int>>& obstacleGrid){
    if (obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 and j == n - 1 and obstacleGrid[i][j]==0) {
                dp[i][j] = 1;
            }
            if (obstacleGrid[i][j] == 0) {
                if (i < m - 1)
                    dp[i][j] += dp[i + 1][j];
                if (j < n - 1)
                    dp[i][j] += dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<"Memoisation "<<uniquePathsWithObstacles(obstacleGrid)<<endl;
    cout<<"Tabulation "<<solve(obstacleGrid)<<endl;
    return 0;
}