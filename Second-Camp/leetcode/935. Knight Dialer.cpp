#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    bool inBound(int i, int j){
        if (i >= 0 && i < 4 && j >= 0 && j < 3 && !(i == 3 && (j == 0 || j == 2)))
            return true;
        return false;
    }
    int knightDialer(int n) {
        int dirs[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        int memo[n][4][3];
        memset(memo, 0, sizeof(memo));
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) memo[0][i][j] = 1;
        memo[0][3][1] = 1;
        for(int level = 1; level < n; level++) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 3; j++) {
                    int prev = memo[level-1][i][j];
                    for(auto& dir: dirs) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (inBound(ni, nj)) memo[level][ni][nj] = (memo[level][ni][nj] + prev)%MOD;
                    }                  
                }
            }
        }  

        int level = n-1;
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                ans = (ans + memo[level][i][j]) % MOD;                   
            }
        }
        return ans;
    }
};