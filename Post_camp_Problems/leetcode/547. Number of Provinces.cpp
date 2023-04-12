#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<bool>& visited) {
        if (visited[i]) return;

        visited[i] = true;
        for(auto& a: graph[i]) {
            dfs(graph, a, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                } 
            }
        }
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                count++;
            }
        }
        return count;
    }
};