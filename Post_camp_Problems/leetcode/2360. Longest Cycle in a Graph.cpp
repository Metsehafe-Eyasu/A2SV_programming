#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max_count = -1;
    int counter = 0;
    void dfs(int index, vector<vector<int>>& graph, vector<int>& color, vector<int>& dist) {
        dist[index] = counter;
        counter++;
        color[index] = 1;
        for(auto& next: graph[index]) {
            if (color[next] == 0)
                dfs(next, graph, color, dist);
            else if (color[next] == 1)
                max_count = max(max_count, dist[index] - dist[next] + 1); 
        }
        color[index] = 2;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);
        vector<int>color(n, 0), dist(n);
        for (int i = 0; i < n; i++)
            if (edges[i] != -1) 
                graph[i].push_back(edges[i]);
        
        for(int i = 0; i < n; i++) {
            if (color[i] == 0) {
                dfs(i, graph, color, dist);
            }
        }
        return max_count;
    }
};