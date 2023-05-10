#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int>q;
        for(auto& p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for(auto&a: graph[top]) {
                inDegree[a]--;
                if (inDegree[a] == 0) q.push(a);
            }
        }

        if (ans.size() != numCourses) return false;
        return true;
    }
};