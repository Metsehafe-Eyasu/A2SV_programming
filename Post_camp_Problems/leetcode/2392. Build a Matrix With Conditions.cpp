#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<char> color;
    bool coloring(int v, vector<vector<int>>& graph) {
        color[v] = 1;
        for (int u : graph[v]) {
            if (color[u] == 0) {
                if (coloring(u, graph))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    bool findCycle(int n, vector<vector<int>>& graph) {
        color.assign(n, 0);

        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && coloring(v, graph))
                return true;
        }
        return false;
    }

    vector<bool> visited;
    void dfs(int v, vector<vector<int>>& graph, vector<int>& ans) {
        visited[v] = true;
        for (int u : graph[v])
            if (!visited[u])
                dfs(u, graph, ans);
        
        ans.push_back(v);
    }

    vector<int> topSort(vector<vector<int>>& graph, int n) {
        visited.assign(n, false);
        vector<int>ans;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i, graph, ans);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>graphRow(k);
        vector<vector<int>>graphCol(k);
        for(auto& pi: rowConditions) graphRow[pi[0]-1].push_back(pi[1]-1);
        for(auto& pi: colConditions) graphCol[pi[0]-1].push_back(pi[1]-1);

        if (findCycle(k, graphRow) || findCycle(k, graphCol)) return {};
        vector<int>arr1 = topSort(graphRow, k);
        vector<int>arr2 = topSort(graphCol, k);
        vector<vector<int>>ans(k, vector<int>(k));
        map<int, int> m;

        for(int i = 0; i < k; i++) m[arr2[i]] = i;
        for(int i = 0; i < k; i++) ans[i][m[arr1[i]]] = arr1[i] + 1;
        return ans;
    }
};