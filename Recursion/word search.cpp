#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
bool isPossible(int i,int j,int m,int n){
    if(i>=0 and i<m and j>=0 and j<n) return true;
    return false;
}
bool solve(vector<vector<char>>& board, string& word,int i,int j,int idx,vector<vector<bool>>& visited){
    if(idx==word.length()) return true;
    visited[i][j]=true;
    bool ans = false;
    for(vector<int> drs:directions){
        int x = i+drs[0];
        int y = j+drs[1];
        //cout<<i<<" "<<j<<"||||"<<x<<" "<<y<<endl;
        if(isPossible(x,y,board.size(),board[0].size()) and board[x][y]==word[idx] and !visited[x][y]){
            //cout<<word[idx]<<" "<<x<<" "<<y<<endl;
            ans = ans or solve(board,word,x,y,idx+1,visited);
        }
    }
    visited[i][j] = false;
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    unordered_map<char,int> freq;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            freq[board[i][j]]++;
        }
    }
    for(char ch:word){
        freq[ch]--;
        if(freq[ch]<0){
            return false;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(word[0]==board[i][j]){
                //cout<<i<<" "<<j<<endl;
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                bool ans = solve(board,word,i,j,1,visited);
                if(ans) return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>>board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout<<exist(board,word)<<endl;
}