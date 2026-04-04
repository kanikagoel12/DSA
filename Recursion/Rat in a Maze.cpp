#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& maze,string& path,vector<string>& res,int i,int j,int n){
    if(i==n-1 and j==n-1){
        if(maze[i][j]==1){
            res.push_back(path);
        }
        return;
    }

    int num = maze[i][j];
    maze[i][j]=-1;

    //down
    if(i+1<n and maze[i+1][j]==1){
        path.push_back('D');
        solve(maze,path,res,i+1,j,n);
        path.pop_back();
    }

    //right
    if(j+1<n and maze[i][j+1]==1){
        path.push_back('R');
        solve(maze,path,res,i,j+1,n);
        path.pop_back();
    }

    //left
    if(j-1>=0 and maze[i][j-1]==1){
        path.push_back('L');
        solve(maze,path,res,i,j-1,n);
        path.pop_back();
    }

    //up
    if(i-1>=0 and maze[i-1][j]==1){
        path.push_back('U');
        solve(maze,path,res,i-1,j,n);
        path.pop_back();
    }

    maze[i][j]=num;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    vector<string> res;
    string path="";
    int n = maze.size();
    if(maze[0][0]==1){
        solve(maze,path,res,0,0,n);
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> res;
    res = ratInMaze(maze);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}