#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>&graph, vector<bool>&visited, int index) {
        if (visited[index]) return 0;
        visited[index] = true;
        int count = 1;
        for(auto& a: graph[index]) {
            count += dfs(graph, visited, a);
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>graph(n);
        for(int i = 0; i < n; i++) {
            long long r = bombs[i][2];
            for(int j = 0; j < n; j++) {
                if (i != j)  {
                    long long xDiff = abs(bombs[i][0] - bombs[j][0]);
                    long long yDiff = abs(bombs[i][1] - bombs[j][1]);
                    if (xDiff*xDiff + yDiff*yDiff <= r*r) {
                        graph[i].push_back(j);
                    }
                }

            }
        }
        int maxCount = 0;
        for(int i = 0; i < n; i++) {
            vector<bool>visited(n, false);
            maxCount = max(maxCount, dfs(graph, visited, i));
        }
        return maxCount;
    }
};