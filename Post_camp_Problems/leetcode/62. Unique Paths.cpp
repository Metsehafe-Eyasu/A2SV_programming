#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>memo;
    int solve(int m, int n) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (memo[m][n] == 0) {
            memo[m][n] = solve(m-1, n) + solve(m, n-1);
        }
        return memo[m][n];
    }
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        return solve(m-1, n-1);
    }
};