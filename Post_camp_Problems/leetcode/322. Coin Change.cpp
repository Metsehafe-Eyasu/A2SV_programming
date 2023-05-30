#include <bits/stdc++.h>
using namespace std;
int INF = 10005;
class Solution {
public:
    vector<int> memo;
    int solve(vector<int>& coins, int n) {
        if (n < 0) return INF;
        if (n == 0) return 0;
        if (!memo[n]) {
            int best = INF;
            for(auto& coin : coins) 
                best = min(best, solve(coins, n-coin)+1);
            memo[n] = best;
        }
        return memo[n];
    }
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(INF, 0);
        int n = solve(coins, amount);
        if (n == INF) return -1;
        return n;
    }
};