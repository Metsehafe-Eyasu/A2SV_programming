#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int count = 1;
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            count += dfs(nx, ny, grid, visited);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]){
                    int count = dfs(i, j, grid, visited);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};