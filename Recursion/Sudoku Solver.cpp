#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board,int k,int i,int j){
        char ch = k+'0';
        for(int r=0;r<9;r++){
            if(board[r][j]==ch){
                return false;
            }
        }

        for(int c=0;c<9;c++){
            if(board[i][c]==ch){
                return false;
            }
        }

        int boxRowStart = (i/3) * 3;
        int boxColStart = (j/3) * 3;

        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(board[r+boxRowStart][c+boxColStart]==ch){
                    return false;
                }
            }
        }

        return true;
    }
bool solve(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                    if(isSafe(board,k,i,j)){
                        board[i][j]=k+'0';
                        if(solve(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}