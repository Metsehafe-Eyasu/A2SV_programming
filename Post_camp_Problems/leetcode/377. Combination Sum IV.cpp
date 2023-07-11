#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        vector<int> memo(target+1, 0);
        memo[0] = 1;
        for (int i = 1; i <= target; i++) {
            ll ans = 0;
            for(int curr: nums) 
                if (i >= curr)
                    ans += memo[i - curr];
            memo[i] = ans;
        }
        return memo[target];
    }
};