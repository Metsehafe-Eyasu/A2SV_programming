#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int color, int index, vector<int>& visited) {
        visited[index] = color;
        for (auto& child : graph[index]) {
            if (visited[child] == visited[index]) return false;
            if (visited[child] == 0 && !dfs(graph, 3 - visited[index], child, visited)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto& dis: dislikes) {
            graph[dis[0]].push_back(dis[1]);
            graph[dis[1]].push_back(dis[0]);
        }
        vector<int> visited(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if (visited[i] == 0 && !dfs(graph, 1, i, visited)) {
                return false;
            }
        }
        return true;
    }
};