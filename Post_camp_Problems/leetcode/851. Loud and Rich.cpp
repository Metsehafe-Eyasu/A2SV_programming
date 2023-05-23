#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n), indegree(n, 0);
        iota(ans.begin(), ans.end(), 0);
        vector<vector<int>>graph(n);
        queue<int>q;
        for(auto& pi: richer) {
            graph[pi[0]].push_back(pi[1]);
            indegree[pi[1]]++;
        }
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) 
                q.push(i);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto& child: graph[curr]) {
                indegree[child]--;
                if (quiet[ans[curr]] < quiet[ans[child]])
                    ans[child] = ans[curr];
                if (indegree[child] == 0) 
                    q.push(child);
            }
        }
        return ans;
    }
};