#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int node, int target, vector<vector<int>>&graph, vector<int>& freq, int parent) {
        if (node == target) {
            freq[node]++;
            return true;
        }
        for (int to: graph[node]) {
            if (to != parent && dfs(to, target, graph, freq, node)) {
                freq[node]++;
                return true;
            }
        }
        return false;
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>>graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> freq(n, 0);
        for(auto trip: trips) {
            dfs(trip[0], trip[1], graph, freq, -1);
        }
        vector<vector<int>> memo(n, vector<int>(2, -1));
        function<int(int, int, int)> recur = [&] (int node, int half, int parent) {
            if (memo[node][half] != -1) return memo[node][half];
            memo[node][half] = freq[node]*price[node];
            if (half) memo[node][half] /= 2;
            for(int next: graph[node]) {
                if (next == parent) continue;

                if (!half)
                    memo[node][half] += min(
                            recur(next, 1-half, node), 
                            recur(next, half, node)
                        );
                else memo[node][half] += recur(next, 1-half, node);
            }
            return memo[node][half];
        };
        int ans = min(recur(0, 0, -1), recur(0, 1, -1));
        return ans;
    }
};