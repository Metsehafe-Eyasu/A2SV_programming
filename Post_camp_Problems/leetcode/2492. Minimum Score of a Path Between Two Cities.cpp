#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    vector<int> parent;
    vector<int> sizes;
    vector<int> score;
public: 
    UnionFind(int size) {
        parent.resize(size);
        sizes.resize(size);
        score.resize(size);
        iota(parent.begin(), parent.end(), 0);
        fill(sizes.begin(), sizes.end(), 1);
        fill(score.begin(), score.end(), 100007);
    }
    int find(int x) {
        if (x != parent[x])
            x = find(parent[x]);
        return parent[x];
    }
    int findScore(int x) {
        x = find(x);
        return score[x];
    }
    void Union(int x, int y, int sc) {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep != y_rep) {
            int s1 = sizes[x_rep];
            int s2 = sizes[y_rep];
            if (s1 < s2) swap(x_rep, y_rep);
            
            sizes[x_rep] += sizes[y_rep];
            parent[y_rep] = parent[x_rep];
        }
        score[x_rep] = min(sc, min(score[x_rep], score[y_rep]));
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind un(n+1);
        for(int i = 0; i < roads.size(); i++) {
            un.Union(roads[i][0], roads[i][1], roads[i][2]);
        }
        return un.findScore(1);
    }
};