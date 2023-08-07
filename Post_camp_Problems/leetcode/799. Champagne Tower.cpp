#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(query_row+1, vector<double>(query_row+1, 0.0));
        memo[0][0] = poured/1.0;
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i ; j++) {
                if (memo[i][j] <= 1) {
                    continue;
                } 
                double extra = memo[i][j] - 1;
                memo[i][j] = 1;
                if (i < query_row) {
                    memo[i+1][j] += extra/2;
                    memo[i+1][j+1] += extra/2;
                }
            }
        }
        return memo[query_row][query_glass];  
    }
};
