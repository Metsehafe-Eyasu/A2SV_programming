#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a, vector<int>&b) {
    return abs(a[0]-a[1]) > abs(b[0]-b[1]);
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        sort(costs.begin(), costs.end(), compare);
        int a= 0, b = 0;
        int ans = 0;
        for(auto cost: costs) {
            if ((cost[0] <= cost[1] && a < n) || b == n) {
                ans+=cost[0];
                a++;
            } else {
                ans+=cost[1];
                b++;
            }
            cout << cost[0] << " " << cost[1];
        }
        return ans;
    }
};