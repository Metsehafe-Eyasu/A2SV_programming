#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return mat;
        int m = mat[0].size();
        vector<vector<int>> grid(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            } 
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + dir[i][0], ny = curr.second + dir[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (grid[nx][ny] > grid[curr.first][curr.second] + 1) {
                        grid[nx][ny] = grid[curr.first][curr.second] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        return grid;
    }
};