#include <bits/stdc++.h>
using namespace std;
int parallelCourses(int n, vector<vector<int>> &prerequisites)
{
    vector<int>ans;
    vector<vector<int>> graph(n+1);
    vector<int> inDegree(n+1, 0);
    queue<int>q;
    for(auto& p: prerequisites) {
        graph[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }
    for(int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    int count = 0;
    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for(auto&a: graph[top]) {
                inDegree[a]--;
                if (inDegree[a] == 0) q.push(a);
            }
        }
        count++;
    }

    if (ans.size() != n) return -1;
    return count;
}
