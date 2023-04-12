#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int color, int start, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != start || visited[i][j])
            return;

        visited[i][j] = true;
        grid[i][j] = color;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, grid, color, start, visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(sr, sc, image, color, image[sr][sc], visited);
        return image;
    }
};