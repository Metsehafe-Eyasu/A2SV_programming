#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>>comb(n);
        for(int i = 0; i < n; i++) {
            comb[i] = make_pair(ages[i], scores[i]);
        }
        sort(comb.begin(), comb.end());
        int grid[n];
        memset(grid, 0, sizeof(grid));
        for(int i = 0; i < n; i++) {
            int points = 0;
            for(int j = 0; j < i; j++) {
                if (comb[i].first > comb[j].first && comb[i].second < comb[j].second)
                    continue;
                points = max(points, grid[j]);
            }
            grid[i] = points + comb[i].second;
        }
        return *max_element(grid, grid + n);
    }
};