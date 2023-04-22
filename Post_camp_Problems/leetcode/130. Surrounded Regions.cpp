#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, bool isMark) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'O' || visited[i][j])
            return;

        visited[i][j] = true;
        if (isMark) 
            grid[i][j] = 'X';
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, grid, visited, isMark);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i*j==0 || i==m-1 || j==n-1) && (board[i][j]=='O'))
                    dfs(i, j, board, visited, false);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(i, j, board, visited, true);
            }
        }
    }
};