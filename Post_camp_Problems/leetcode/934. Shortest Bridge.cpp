#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    bool inBound(int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }
    void dfs(int i, int j, queue<pair<int, int>>&q, vector<vector<int>>& grid) {
        if (!inBound(i, j, grid.size()) || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, q, grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int fx, fy, n = grid.size();
        bool found = false;
        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fx = i, fy = j;
                    found = true;
                    break;
                }
            }
        }
        queue<pair<int, int>> q;
        dfs(fx, fy, q, grid);
        int distance = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int z = 0; z < len; z++) {
                auto [cx, cy] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (inBound(nx, ny, grid.size())) {
                        if (grid[nx][ny] == 1) return distance;
                        else if (grid[nx][ny] == 0) {
                            grid[nx][ny] = -1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            distance++;
        }
        return -1;
    }
};