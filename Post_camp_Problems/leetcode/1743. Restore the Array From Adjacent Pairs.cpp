#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>graph;
        unordered_map<int, int>indegree;
        vector<int> ans;
        for(auto& pi: adjacentPairs) {
            graph[pi[0]].push_back(pi[1]);
            graph[pi[1]].push_back(pi[0]);
            indegree[pi[0]]++;
            indegree[pi[1]]++;
        }
        int start = -1, end = -1;
        for(auto [ind, val]: indegree) {
            if (val == 1) {
                if (start == -1)
                    start = ind;
                else 
                    end = ind;
            }
        }
        queue<int>q;
        q.push(start);
        cout << start << endl;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto&a: graph[curr]) {
                cout << a << endl;
                indegree[a]--;
                if (indegree[a] == 1) q.push(a);
            }
        }
        ans.push_back(end);
        return ans;
    }
};