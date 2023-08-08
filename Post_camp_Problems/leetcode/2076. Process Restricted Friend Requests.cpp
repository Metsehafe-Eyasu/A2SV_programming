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
    bool isCon(int x, int y) {
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
    bool checker(int i, int j, UnionFind& uf, vector<vector<int>>& restrictions) {
        for(auto& pr: restrictions) {
            if (
                (uf.isCon(i, pr[0]) && uf.isCon(j, pr[1])) || 
                (uf.isCon(i, pr[1]) && uf.isCon(j, pr[0]))
            ) {
                return false;
            }
        }
        return true;
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind uf(n);
        int k = requests.size();
        vector<bool>ans(k);
        int i = 0;
        for(auto req: requests) {
            bool res = checker(req[0], req[1], uf, restrictions);
            if (res) uf.unite(req[0], req[1]);
            ans[i++] = res;
        }
        return ans;
    }
};