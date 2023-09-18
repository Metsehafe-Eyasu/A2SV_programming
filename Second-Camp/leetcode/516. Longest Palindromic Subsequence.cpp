#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n), dpPrev(n);
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = i-1; j >= 0; j--) {
                if (s[i] == s[j]) dp[j] = dpPrev[j+1] + 2;
                else dp[j] = max(dpPrev[j], dp[j+1]);
            }
            dpPrev = dp;
        }
        return dp[0];
    }        
};