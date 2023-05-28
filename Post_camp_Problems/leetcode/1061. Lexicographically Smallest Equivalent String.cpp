#include <bits/stdc++.h>
using namespace std;
struct UnionFind
{
    vector<int> parent;
    UnionFind(int n) : parent(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (x > y) swap(x, y);
        parent[y] = x;
        return true;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for(auto&a: baseStr) {
            ans += uf.find(a - 'a') + 'a';
        }
        return ans;
    }
};