#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector<int>memo(n+1, 0);
        set<int> all_days(days.begin(), days.end());
        for(int i = 1; i <= n; i++) {
            if (all_days.count(i))
                memo[i] = min({
                    costs[0] + memo[i-1],
                    costs[1] + memo[max(i-7, 0)], 
                    costs[2] + memo[max(i-30, 0)]
                });
            else 
                memo[i] = memo[i-1];
        }
        return memo[n];
    }
};