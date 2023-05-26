#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));
        queue<int>q;
        for(auto& p: prerequisites) {
            graph[p[0]].push_back(p[1]);
            inDegree[p[1]]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto&a: graph[top]) {
                grid[top][a] = true;
                for(int i = 0; i < numCourses; i++) 
                    if (grid[i][top])
                        grid[i][a] = true;
                inDegree[a]--;
                if (inDegree[a] == 0) q.push(a);
            }
        }

        for(auto& pi: queries) {
            ans.push_back(grid[pi[0]][pi[1]]);
        }
        return ans;
    }
};