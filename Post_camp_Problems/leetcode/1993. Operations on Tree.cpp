#include <bits/stdc++.h>
using namespace std;
class LockingTree {
public:
    vector<vector<int>>graph;
    vector<int>origin;
    vector<int>userGraph;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        graph.resize(n);
        userGraph.resize(n, -1);
        origin = parent;
        for(int i = 0; i < n; i++) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (userGraph[num] != -1) return false;
        userGraph[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (userGraph[num] != user) return false;
        userGraph[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (userGraph[num] != -1 || !dfs(num)) return false;

        bool hasLockedDescendant = false;
        function<void(int)> findLockedDescendant = [&](int node) {
            if (userGraph[node] != -1) {
                hasLockedDescendant = true;
                return;
            }
            for (int child : graph[node])
                findLockedDescendant(child);
        };
        findLockedDescendant(num);
        if (!hasLockedDescendant) return false;

        userGraph[num] = user;
        modif(num);
        return true;
    }

    bool dfs(int num) {
        if (userGraph[num] != -1) return false;
        if (origin[num] == -1) return true;
        return dfs(origin[num]);
    }
    void modif(int num) {
        if (graph[num].empty()) return;
        for(auto&a: graph[num]) {
            userGraph[a] = -1;
            modif(a);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */