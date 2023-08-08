#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> all_possible(n*(n-1)/2);
        int x = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pair<int, pair<int, int>> curr_pair = {diff, {i, j}};
                all_possible[x++] = curr_pair;
            }
        }
        sort(all_possible.begin(), all_possible.end());
        UnionFind uf(n);
        int ans = 0;
        for(int i = 0; i < x; i++) {
            auto [diff, pts_pair] = all_possible[i];
            auto [px, py] = pts_pair;
            if (uf.unite(px, py)) {
                ans += diff;
            }
        }
        return ans;
    }
};