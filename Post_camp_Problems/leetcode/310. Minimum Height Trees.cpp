#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if (n < 2){
            for (int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
        }

        vector<vector<int>>graph(n);
        vector<int>indegree(n, 0);
        vector<bool>visited(n, false);
        for (auto& pi: edges) {
            graph[pi[0]].push_back(pi[1]);
            graph[pi[1]].push_back(pi[0]);
            indegree[pi[0]]++;
            indegree[pi[1]]++;
        }

        queue<int>q;
        for(int i = 0; i < n; i++)
            if (indegree[i] == 1) {
                q.push(i);
                ans.push_back(i);
                visited[i] = true;
            }
        
        while (!q.empty()) {
            int len = q.size();
            vector<int>temp;
            for(int _ = 0; _ < len; _++) {
                int curr = q.front();
                q.pop();
                for(auto& next: graph[curr]) {
                    indegree[next]--;
                    if(indegree[next] == 1 && !visited[next]) {
                        q.push(next);
                        temp.push_back(next);
                        visited[next] = true;
                    }
                }
            }
            if (!temp.empty()) {
                ans.clear();
                copy(temp.begin(), temp.end(), back_inserter(ans));
            }
        }
        return ans;
    }
};