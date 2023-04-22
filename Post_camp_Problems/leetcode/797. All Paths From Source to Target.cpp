#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>answer;
    vector<int>path;
    int last;
    void dfs(vector<vector<int>>& graph, int index) {
        if (index == last) {
            answer.push_back(path);
            return;
        }
        for(auto& a: graph[index]){
            path.push_back(a);
            dfs(graph, a);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        last = graph.size() - 1;
        path.push_back(0);
        dfs(graph, 0);
        return answer;
    }
};