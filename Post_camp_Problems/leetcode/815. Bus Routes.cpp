#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (target == source) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> graph;
        vector<bool>visited(n, false);
        queue<int>q;

        for(int i = 0; i < n; i++)
            for(auto& pos: routes[i]) 
                graph[pos].push_back(i);
                
        for (auto curr: graph[source]) {
            visited[curr] = true;
            q.push(curr);
        }
        int ans = 0;
        while (!q.empty()) {
            ans++;
            for (int k = q.size(); k > 0; k--) {
                int curr = q.front();
                q.pop();
                for(auto route: routes[curr]) {
                    if (route == target) return ans;
                    for(int i = 0; i < graph[route].size(); i++) {
                        if (!visited[graph[route][i]]) {
                            visited[graph[route][i]] = true;
                            q.push(graph[route][i]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};