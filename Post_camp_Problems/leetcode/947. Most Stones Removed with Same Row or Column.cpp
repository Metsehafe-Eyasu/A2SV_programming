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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(20001); 
        
        for (const auto& stone : stones) {
            uf.unite(stone[0], stone[1] + 10001);
        }
        
        unordered_map<int, int> groups;
        for (const auto& stone : stones) {
            groups[uf.find(stone[0])]++;
        }
        
        int result = 0;
        for (const auto& group : groups) {
            result += group.second - 1;
        }
        
        return result;
    }
};