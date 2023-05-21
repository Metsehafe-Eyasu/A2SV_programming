#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int>inDegree(n);
        vector<bool>visited(n, false);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        unordered_map<int, set<int>>hash;
        queue<int>q;
        for(int i = 0; i < n; i++)
            if (inDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto& edge: graph[curr]) {
                set<int> parent = hash[curr];
                if (!visited[edge]) {
                    hash[edge].insert(curr);
                    hash[edge].insert(parent.begin(), parent.end());
                    if (--inDegree[edge] == 0){
                        q.push(edge);
                        visited[edge] = true;
                    }
                }
            }
        }
        vector<vector<int>>ans(n);
        for(int i = 0; i < n; i++) {
            for(auto&a: hash[i]) {
                ans[i].push_back(a);
            }
        }        
        return ans;
    }
};