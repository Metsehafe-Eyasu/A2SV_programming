#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<pair<int, int>> memo(n, {0, 0});
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (rating[i] < rating[j]) {
                    memo[i].first++;
                    ans += memo[j].first;
                } 
                else if (rating[i] > rating[j]) {
                    memo[i].second++;
                    ans += memo[j].second;
                } 
            }
        }
        return ans;
    }
};