#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& sources, int index) {
        if (visited[index]) {
            sources[index] = false;
            return;
        }

        visited[index] = true;
        for(auto& a: adj[index]) {
            dfs(adj, visited, sources, a);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        vector<bool> sources(n, true);

        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i = 0; i < n; i++)
            dfs(adj, visited, sources, i);

        vector<int>ans;
        for(int i = 0; i < n; i++) {
            if (sources[i]) ans.push_back(i);
        }
        return ans;
    }
};