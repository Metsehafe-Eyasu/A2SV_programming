#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto& road: roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        int maxCount = 0;
        for (int i = 0; i < n - 1; i++) {
            for(int j = i+1; j < n; j++) {
                int curr = adj[i].size() + adj[j].size();
                for(auto& a: adj[i]) {
                    if (a == j) {
                        curr--;
                        break;
                    }
                }
                maxCount = max(maxCount, curr);
            }
        }
        return maxCount;
    }
};