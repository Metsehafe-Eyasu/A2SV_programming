#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
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
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        UnionFind uf(n+1);
        uf.unite(0, firstPerson);
        int i = 0;
        while(i < meetings.size()){
            int time = meetings[i][2];
            int start = i;
            while(i < meetings.size() && time == meetings[i][2]){
                uf.unite(meetings[i][0], meetings[i][1]);
                i++;
            }
            for(int j = start; j < i; j++){
                if(!uf.isConnected(meetings[j][0], 0)){
                    uf.parent[meetings[j][0]] = meetings[j][0];
                    uf.parent[meetings[j][1]] = meetings[j][1];
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++) {
            if (uf.isConnected(0, i)) ans.push_back(i);
        }
        return ans;
    }
};