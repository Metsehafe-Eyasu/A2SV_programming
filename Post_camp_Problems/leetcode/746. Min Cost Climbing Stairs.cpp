#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int>memo;
    int dp(int n, vector<int>& cost) {
        if (n < 0) return 0;
        if (n < 2) return cost[n];
        if (!memo[n]) memo[n] = cost[n] + min(dp(n-1, cost), dp(n-2, cost));
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(dp(n-1, cost), dp(n-2, cost));
    }
};