#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,vector<string>& mat,int n){
    //check the column;
    for(int i=0;i<n;i++){
        if(mat[i][col]=='Q'){
            return false;
        }
    }
    //check the diagonal
    int i=row;
    int j=col;
    while(i>=0 and j>=0){
        if(mat[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i=row;
    j=col;
    while(i>=0 and j<n){
        if(mat[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}
void PlaceQueen(vector<vector<string>>& res,vector<string>& mat,int row,int n){
    //base case
    if(row==n){
        vector<string> ans;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp.push_back(mat[i][j]);
            }
            ans.push_back(temp);
        }
        res.push_back(ans);
    }

    for(int j=0;j<n;j++){
        if(isSafe(row,j,mat,n)){
            mat[row][j]='Q';
            PlaceQueen(res,mat,row+1,n);
            mat[row][j]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> mat(n,string(n,'.'));

    PlaceQueen(res,mat,0,n);
    return res;
}

int main()
{
    vector<vector<string>> res;
    res=solveNQueens(5);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
    }

    return 0;
}