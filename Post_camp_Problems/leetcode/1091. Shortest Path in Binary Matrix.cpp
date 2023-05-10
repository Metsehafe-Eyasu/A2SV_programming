#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inBound(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 0 || visited[i][j]) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>>q;
        vector<pair<int, int>> dirs = {{0, 1},{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1},{-1, 0},{-1, 1}};
        q.push({0, 0});
        visited[0][0] = true;
        int count = 0;
        while (!q.empty()) {
            int len = q.size();
            count++;
            for(int i = 0; i < len; i++) {
                pair<int, int> curr = q.front();
                if (curr.first == n-1 && curr.second == n-1) return count;
                q.pop();
                for(int k = 0; k < 8; k++) {
                    int nx = dirs[k].first + curr.first;
                    int ny = dirs[k].second + curr.second;
                    if (inBound(nx, ny, grid, visited)) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};