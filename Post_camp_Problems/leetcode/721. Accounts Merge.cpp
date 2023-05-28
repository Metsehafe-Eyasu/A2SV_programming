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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> group;
        for(int i = 0; i < n; i++) {
            int len = accounts[i].size();
            for(int j = 1; j < len; j++) {
                string mail = accounts[i][j];
                if (!group.count(mail)) group[mail] = i;
                else uf.unite(i, group[mail]);
            }
        }

        unordered_map<int, vector<string>> indexedGroup;
        for(auto& mail: group) {
            string email = mail.first;
            int g = mail.second;
            indexedGroup[uf.find(g)].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto& mail: indexedGroup) {
            int g = mail.first;
            vector<string>arr = {accounts[g][0]};
            arr.insert(arr.end(), mail.second.begin(), mail.second.end());
            sort(arr.begin() + 1, arr.end());
            ans.push_back(arr);
        }
        return ans;
    }
};