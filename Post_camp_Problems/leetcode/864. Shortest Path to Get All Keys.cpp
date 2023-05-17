#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].length();
        queue<vector<int>> q;
        vector<vector<int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        unordered_map<int, set<pair<int, int>>> visited;

        unordered_set<char> keySet;
        unordered_set<char> lockSet;
        int allKeys = 0;
        int startR = -1, startC = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char cell = grid[i][j];
                if (cell >= 'a' && cell <= 'f') {
                    allKeys += (1 << (cell - 'a'));
                    keySet.insert(cell);
                }
                if (cell >= 'A' && cell <= 'F') {
                    lockSet.insert(cell);
                }
                if (cell == '@') {
                    startR = i;
                    startC = j;
                }
            }
        }

        q.push({startR, startC, 0, 0});
        visited[0].insert(make_pair(startR, startC));

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int curR = cur[0], curC = cur[1], keys = cur[2], dist = cur[3];
            for (vector<int>& move : moves) {
                int newR = curR + move[0], newC = curC + move[1];
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] != '#') {
                    char cell = grid[newR][newC];
                    if (keySet.count(cell)) {
                        if (((1 << (cell - 'a')) & keys) != 0) continue;
                        int newKeys = (keys | (1 << (cell - 'a')));

                        if (newKeys == allKeys) return dist + 1;
                        visited[newKeys].insert(make_pair(newR, newC));
                        q.push({newR, newC, newKeys, dist + 1});
                    }

                    if (lockSet.count(cell) && ((keys & (1 << (cell - 'A'))) == 0)) {
                        continue;
                    } else if (!visited[keys].count(make_pair(newR, newC))) {
                        visited[keys].insert(make_pair(newR, newC));
                        q.push({newR, newC, keys, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};