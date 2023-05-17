#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    vector<int> parent;
    vector<int> sizes;
public: 
    UnionFind(int size) {
        parent.resize(size);
        sizes.resize(size);
        iota(parent.begin(), parent.end(), 0);
        fill(sizes.begin(), sizes.end(), 1);
    }
    int find(int x) {
        if (x != parent[x])
            x = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y) {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep != y_rep) {
            int s1 = sizes[x_rep];
            int s2 = sizes[y_rep];
            if (s1 < s2) swap(x_rep, y_rep);
            
            sizes[x_rep] += sizes[y_rep];
            parent[y_rep] = parent[x_rep];
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind un(n);
        for(auto& pair: edges) {
            un.Union(pair[0], pair[1]);
        }
        return un.connected(source, destination);
    }
};