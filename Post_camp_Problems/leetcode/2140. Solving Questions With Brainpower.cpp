#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>memo(n, 0);
        memo[n-1] = questions[n-1][0];
        for (int i = n-2; i >=0; i--) {
            memo[i] = questions[i][0];
            int steps = questions[i][1];
            if (i+steps+1 < n) {
                memo[i] += memo[i+steps+1];
            }
            memo[i] = max(memo[i], memo[i+1]);
        }
        return memo[0];
    }
};