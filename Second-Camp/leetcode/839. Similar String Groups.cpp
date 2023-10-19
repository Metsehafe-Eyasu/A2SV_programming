#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    int comp;
    UnionFind(int n) : parent(n), size(n, 1), comp(n) {
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
        comp--;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};
class Solution {
public:
    bool similar(string& a, string&b) {
        int dif = 0;
        for(int i = 0; i < a.size(); i++) 
            if (a[i] != b[i]) 
                dif++;
        return dif == 0 || dif == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (similar(strs[i], strs[j]))
                    uf.unite(i, j);
        return uf.comp;
    }
};