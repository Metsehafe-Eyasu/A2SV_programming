#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> t3i;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, unordered_map<int, int>>graph;
        for(auto flight: flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        priority_queue<t3i, vector<t3i>, greater<t3i>>pq;
        vector<long long>distances(n+1, INT_MAX);
        distances[src] = 0;
        pq.push({-1, 0, src});
        while(!pq.empty()) {
            auto [steps, dist, source] = pq.top();
            cout << "source: " << source << " dist: " << dist << " steps: " << steps << "\n";
            pq.pop();
            // if (source == dst && steps <= k) return dist;
            for(auto [neighbour, n_dist]: graph[source]) {
                int next_dist = n_dist + dist;
                if (next_dist < distances[neighbour] && steps < k) {
                    distances[neighbour] = next_dist;
                    pq.push({steps+1, next_dist, neighbour});
                }
            }
        }
        return distances[dst] >= INT_MAX ? -1 : distances[dst];
    }
};