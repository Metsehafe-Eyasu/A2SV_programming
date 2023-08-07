#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, prev = 0;
        for(int curr: values) {
            ans = max(ans, curr+prev);
            prev = max(prev, curr) - 1;
        }
        return ans;
    }
};
