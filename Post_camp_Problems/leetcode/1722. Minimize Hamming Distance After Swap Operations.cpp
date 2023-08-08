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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        for(auto& curr_pair: allowedSwaps) {
            uf.unite(curr_pair[0], curr_pair[1]);
        }
        unordered_map<int, unordered_map<int, int>> container;
        for (int i = 0; i < n; i++) {
            container[uf.find(i)][source[i]]++;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int>& freq = container[uf.find(i)];
            if (freq[target[i]] <= 0) continue;
            else {
                ans--;
                freq[target[i]]--;
            }
        }
        return ans;
    }
};