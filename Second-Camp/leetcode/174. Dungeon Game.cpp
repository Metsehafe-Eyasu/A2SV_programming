#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, INT_MAX));
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int val = dungeon[i][j];
                int prev = min(memo[i+1][j], memo[i][j+1]);
                if (prev == INT_MAX) prev = 0;
                memo[i][j] = max(0, prev - val);
            }
        }
        return memo[0][0] + 1;
    }
};