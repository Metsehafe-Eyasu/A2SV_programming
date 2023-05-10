#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int currNode, vector<vector<int>>& graph, vector<int>&colors) {
        if (colors[currNode] == 2) return true;
        if (colors[currNode] == 1) return false;
        colors[currNode] = 1;
        for(auto&a : graph[currNode]) {
            if (!dfs(a, graph, colors)) return false;
        }
        colors[currNode] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<int>colors(n, 0);
        for(int i = 0; i < n; i++) {
            if (dfs(i, graph, colors)) ans.push_back(i);
        }
        return ans;
    }
};