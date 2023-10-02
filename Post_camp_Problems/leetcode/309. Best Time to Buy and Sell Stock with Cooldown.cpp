#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(2, vector<int>(n, 0));
        memo[1][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            memo[0][i] = max(memo[0][i-1], memo[1][i-1] + prices[i]);
            memo[1][i] = max(memo[1][i-1], (i >= 2 ? memo[0][i-2] : 0) - prices[i]);
        }
        return memo[0][n-1];
    }
};
