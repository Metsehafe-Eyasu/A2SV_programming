#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        priority_queue<pair<double, int>> q;
        q.push(make_pair(1.0, start));
        while (!q.empty()) {
            auto [currdist, currindex] = q.top();
            q.pop();
            if (currindex == end) return currdist;
            for (auto x : adj[currindex]) {
                int node = x.first;
                double prob = x.second;
                double newProb = currdist * prob;
                if (newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(make_pair(newProb, node));
                }
            }
        }
        return dist[end];
    }
};