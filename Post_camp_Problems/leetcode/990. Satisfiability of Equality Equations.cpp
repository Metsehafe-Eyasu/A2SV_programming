#include <bits/stdc++.h>
using namespace std;
struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int i = eq[0] - 'a', j = eq[3] - 'a';
                uf.unite(i, j);
            }
        }
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                int i = eq[0] - 'a', j = eq[3] - 'a';
                if (uf.isConnected(i, j)) return false;
            }
        }
        return true;
    }
};