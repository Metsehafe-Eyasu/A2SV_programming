#include <bits/stdc++.h>
using namespace std;
struct PairHash {
  size_t operator()(const pair<int, int>& p) const {
    return p.first * 1000000 + p.second;
  }
};


class UnionFind {
public:
    unordered_map<pair<int, int>, pair<int, int>, PairHash> parent;
    unordered_map<pair<int, int>, int, PairHash> rank;

    UnionFind(int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
            pair<int, int> p = make_pair(i, j);
            parent[p] = p;
            rank[p] = 0;
            }
        }
    }

    pair<int, int> find(pair<int, int> x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_(pair<int, int> x, pair<int, int> y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (rank[x] < rank[y]) parent[x] = y; 
            else if (rank[x] > rank[y]) parent[y] = x;
            else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    bool connected(pair<int, int> x, pair<int, int> y) {
        return find(x) == find(y);
    }
};


class Solution {
public:
    bool isBound(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> streets = {
            {1, {1, 1, 0, 0}},
            {2, {0, 0, 1, 1}},
            {3, {1, 0, 0, 1}},
            {4, {0, 1, 0, 1}},
            {5, {1, 0, 1, 0}},
            {6, {0, 1, 1, 0}},
        };
        int n = grid.size(), m = grid[0].size();
        UnionFind uf(n, m);
        vector<vector<int>> dirs = {{0, 1}, {1, 0}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int curr = grid[i][j];
                for(int k = 0; k < 2; k++) {
                    pair<int, int> nextLoc = {i+dirs[k][0], j+dirs[k][1]};
                    if (isBound(nextLoc.first, nextLoc.second, n, m)) {
                        int next = grid[nextLoc.first][nextLoc.second];
                        if (k == 0 && streets[next][0] && streets[curr][1]) {
                            uf.union_(nextLoc, {i, j});
                        }
                        else if (k == 1 && streets[curr][3] && streets[next][2]) {
                            uf.union_(nextLoc, {i, j});
                        }
                    }
                }
            }
        }
        return uf.connected({0, 0}, {n-1, m-1});
    }
};