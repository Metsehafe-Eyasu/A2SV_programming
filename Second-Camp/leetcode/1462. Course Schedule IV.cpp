#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dist(numCourses, vector<int>(numCourses, INT_MAX));
        for(int i = 0; i < prerequisites.size(); i++) {
            int row = prerequisites[i][0], col = prerequisites[i][1]; 
            dist[row][col] = 1;
        }
        for(int i = 0; i < numCourses; i++) dist[i][i] = 0;
        for(int k = 0; k < numCourses; k++) 
            for(int i = 0; i < numCourses; i++) 
                for(int j = 0; j < numCourses; j++) 
                    dist[i][j] = min((long)dist[i][j], (long)dist[i][k] + (long)dist[k][j]);
        vector<bool>ans;
        for(int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            ans.push_back(dist[from][to] != INT_MAX);
        }
        return ans;
    }
};