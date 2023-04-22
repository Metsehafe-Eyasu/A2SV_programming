#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dfs(int curr, int parent, vector<vector<int>>& graph, vector<int>& ans, string& labels) {
        vector<int>alpha(26);
        alpha[labels[curr] - 'a'] = 1;
        for(auto&a: graph[curr]) {
            if (a == parent) continue;
            vector<int> children = dfs(a, curr, graph, ans, labels);
            for(int i = 0; i < 26; i++) {
                alpha[i] += children[i];
            }
        }
        ans[curr] = alpha[labels[curr] - 'a'];
        return alpha;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto& a: edges) {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        vector<int>ans(n, 0);
        dfs(0, -1, graph, ans, labels);
        return ans;
    }
};