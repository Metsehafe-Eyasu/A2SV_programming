#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inBound(int i, int j, vector<vector<char>>& maze) {
        int n = maze.size(), m = maze[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '+')
            return false;
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        visited[entrance[0]][entrance[1]] = true;
        pair<int, int> ent = {entrance[0], entrance[1]}; 
        q.push(ent);
        int step;
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty()) {
            int len = q.size();
            for(int _ = 0; _ < len; _++) {
                pair<int, int> curr = q.front();
                q.pop();
                if (
                    curr != ent && 
                    (curr.first == 0 || curr.first == n - 1 || curr.second == 0 || curr.second == m - 1)) 
                    return step;

                for(int k = 0; k < 4; k++ ) {
                    int nx = curr.first + dir[k][0], ny = curr.second + dir[k][1];
                    if (inBound(nx, ny, maze)) {
                        q.push({nx, ny});
                        maze[nx][ny] = '+';
                    }
                }
            }
            step++;
        }

        return -1;
    }
};