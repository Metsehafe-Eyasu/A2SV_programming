#include <bits/stdc++.h>
using namespace std;
struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y){
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
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int qCount = queries.size();
        vector<vector<int>>indexedQueries(qCount);
        for (int i = 0; i < qCount; i++) {
            indexedQueries[i] = queries[i];
            indexedQueries[i].push_back(i);
        }
        int edgeIndex = 0;
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(indexedQueries.begin(), indexedQueries.end(), compare);
        vector<bool>ans(qCount);
        UnionFind uf(n);
        for(auto& query: indexedQueries) {
            int from = query[0], to = query[1];
            int limit = query[2], qIndex = query[3];
            while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {
                int node1 = edgeList[edgeIndex][0];
                int node2 = edgeList[edgeIndex][1];
                uf.unite(node1, node2);
                edgeIndex++;
            } 
            ans[qIndex] = uf.isConnected(from, to);
        }
        return ans;
    }
};