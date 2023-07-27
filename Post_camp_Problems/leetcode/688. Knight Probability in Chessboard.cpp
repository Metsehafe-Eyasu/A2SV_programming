#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inBound(int i, int j, int n) {
        if (i >= 0 && i < n && j >= 0 && j < n)
            return true;
        return false;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector dp(k + 1, vector (n, vector<double>(n, 0.0)));
        dp[0][row][column] = 1;
        for (int moves = 1; moves <= k; moves++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (const auto& direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;
                        if (inBound(prevI, prevJ, n)) {
                            dp[moves][i][j] += dp[moves - 1][prevI][prevJ] / 8;
                        }
                    }
                }
            }
        }
        double total = 0.0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                total += dp[k][i][j];
                
        return total;
    }
};
