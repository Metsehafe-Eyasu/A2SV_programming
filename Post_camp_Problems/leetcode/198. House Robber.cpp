#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
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
};