#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n+1, 100000));
        memo[0][1] = triangle[0][0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                memo[i][j+1] = triangle[i][j] + min(memo[i-1][j], memo[i-1][j+1]);
            }
        }
        int min_ = INT_MAX;
        for(int i = 1; i <= n; i++) {
            min_ = min(min_, memo[n-1][i]);
        }
        return min_;
    }
};
