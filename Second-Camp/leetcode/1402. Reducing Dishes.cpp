#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculator(vector<int>& sat, vector<vector<int>>&memo, int index, int time) {
        if (index == sat.size()) return 0;
        if (memo[index][time] == -1) 
            memo[index][time] = max(
                sat[index]*time + calculator(sat, memo, index + 1, time + 1),
                calculator(sat, memo, index + 1, time)
            );
        return memo[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>memo(n + 1, (vector<int>(n + 1, -1)));
        
        return calculator(satisfaction, memo, 0, 1);
    }
};