#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp(vector<int>&nums) {
        int n = nums.size();
        vector<int>memo(n, 0);
        memo[0] = nums[0];
        memo[1] = nums[1];
        for(int i = 2; i < n; i++) {
            memo[i] = nums[i];  
            if (i-3 >= 0) {
                memo[i] += max(memo[i-3], memo[i-2]);
            } else {
                memo[i] += memo[i-2];
            }
        }
        return max(memo[n-1], memo[n-2]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return nums[0];
        int k = nums[0];
        nums[0] = 0;
        int ans = dp(nums);
        nums[0] = k;
        nums[n-1] = 0;
        return max(ans, dp(nums));
    }
};