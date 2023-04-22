#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int index, vector<vector<int>>& graph, string& s, int& answer) {
        int first = 0, second = 0;
        for(auto& a: graph[index]) {
            int x = dfs(a, graph, s, answer);
            if (s[index] == s[a]) continue;
            if (x > first){
                second = first;
                first = x;
            } else if (x > second){
                second = x;
            }
        }

        answer = max(answer, first + second + 1);
        return first + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>graph(n);
        for(int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }
        int answer = 1;
        dfs(0, graph, s, answer);
        return answer;
    }
};