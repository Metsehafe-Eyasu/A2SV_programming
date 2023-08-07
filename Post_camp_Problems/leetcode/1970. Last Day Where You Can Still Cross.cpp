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
    bool inBound(int i, int j, int n, int m) {
        if (i >= 0 && j >= 0 && i < n && j < m) return true;
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 1));
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int allCells = row*col;
        int start = allCells, end = allCells+1;
        UnionFind uf(allCells+2);
        for (int c = allCells - 1; c >= 0; c--) {
            int x = cells[c][0] - 1;
            int y = cells[c][1] - 1;
            int node = x*col + y;
            grid[x][y] = 0;
            for(int k = 0; k < 4; k++) {
                int next_x = x + dx[k];
                int next_y = y + dy[k];
                if (inBound(next_x, next_y, row, col) && grid[next_x][next_y] == 0) {
                    int next = next_x*col + next_y;
                    uf.unite(node, next);
                }
            }
            if (x == 0) uf.unite(start, node);
            if (x == row-1) uf.unite(end, node);
            if (uf.isConnected(start, end)) return c;
        }
        return 0;
    }
};