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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind un(n);
        for(auto& p: pairs) {
            un.unite(p[0], p[1]);
        }
        unordered_map<int, map<int, int>> hash;
        for(int i = 0; i < n; i++) {
            hash[un.find(i)][s[i]]++;
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            int min_ = hash[un.find(i)].begin()->first;
            ans += min_;
            if (--hash[un.find(i)][min_] == 0) {
                hash[un.find(i)].erase(min_);
            }
        }
        return ans;
    }
};