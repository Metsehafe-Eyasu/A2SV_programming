#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inBound(int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'E')
            return;
        
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

        int count = 0;
        for(int k=0;k<8;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (inBound(m, n, nx, ny) && grid[nx][ny] == 'M') {
                count++;
            }
        }
        if (count != 0) {
            grid[i][j] = '0' + count;
        } else {
            grid[i][j] = 'B';
            for(int k=0;k<8;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                dfs(nx, ny, grid);
            }
        }  
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') board[i][j] = 'X';
        else dfs(i, j, board);

        return board;
    }
};