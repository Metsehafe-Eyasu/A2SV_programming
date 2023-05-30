#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int>memo;
    int dp(int n) {
        if (n < 2) return n;
        if (!memo[n]) {
            if (n%2 == 0) memo[n] = dp(n/2);
            else {
                int m = (n-1)/2;
                memo[n] = dp(m) + dp(m+1);
            }
        }
        return memo[n];
    }
    int getMaximumGenerated(int n) {
        int max_ = 0;
        for(int i = 1; i <= n; i++) {
            max_ = max(max_, dp(i));
        }
        return max_;
    }
};