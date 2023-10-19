#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2) return false;
        int n = nums.size();
        sum /= 2;
        vector<vector<bool>> memo(n, vector<bool>(sum+1, false));
        for(int i = 0; i < n; i++) memo[i][0] = true;
        if(nums[0] <= sum) memo[0][nums[0]] = true;
        for(int i=1; i<n; i++){
            for(int target=1; target <= sum; target++){
                bool take = false;
                bool notTake = memo[i-1][target];
                if(nums[i] <= target) take = memo[i-1][target-nums[i]];
                memo[i][target] = notTake || take;
            }
        }
        return memo[n-1][sum];

    }
};
