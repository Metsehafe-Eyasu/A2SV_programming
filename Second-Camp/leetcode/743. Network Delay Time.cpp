#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, unordered_map<int, int>>graph;
        for(auto time: times) {
            graph[time[0]][time[1]] = time[2];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>distances(n+1, 1e3);
        vector<bool>visited(n+1, false);
        distances[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [weight, source] = pq.top();
            pq.pop();
            if (visited[source]) continue;
            visited[source] = true;
            for(auto [neighbour, n_weight]: graph[source]) {
                int next_dist = n_weight + weight;
                if (next_dist < distances[neighbour]) {
                    distances[neighbour] = next_dist;
                    pq.push({next_dist, neighbour});
                }
            }
        }
        for(int i = 1; i <= n; i++) 
            if (!visited[i]) return -1;
        int ans = *max_element(distances.begin()+1, distances.end());
        return ans;
    }
};