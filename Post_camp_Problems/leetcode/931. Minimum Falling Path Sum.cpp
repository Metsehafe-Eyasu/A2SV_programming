#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for(int i= 0; i < n; i++) {
            memo[0][i] = matrix[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int x = (j > 0) ? memo[i-1][j-1] + matrix[i][j] : INT_MAX;
                int y = memo[i-1][j] + matrix[i][j];
                int z = (j < n - 1) ? memo[i-1][j+1] + matrix[i][j] : INT_MAX;
                memo[i][j] = min({x, y, z});
            }
        }

        int min_ = INT_MAX;
        for(int i = 0; i < n; i++) {
            min_ = min(min_, memo[n-1][i]);
        }
        return min_;
    }
};
