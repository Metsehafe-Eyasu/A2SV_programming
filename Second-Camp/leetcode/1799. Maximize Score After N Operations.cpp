#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int backtrack(int mask, int pairsPicked, vector<int>&nums, vector<int>&memo) {
        if (pairsPicked*2 == nums.size()) return 0;
        if (memo[mask] != -1) return memo[mask];
        int maxScore = 0;
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if ((mask >> i) & 1 || (mask >> j) & 1) continue;
                int newMask = mask | 1 << i | 1 << j;
                int currScore = (pairsPicked+1)*__gcd(nums[i], nums[j]);
                int remainingScore = backtrack(newMask, pairsPicked+1, nums, memo);
                maxScore = max(maxScore, currScore+remainingScore);
            }
        }
        memo[mask] = maxScore;
        return memo[mask];
    }
    int maxScore(vector<int>& nums) {
        int size = 1 << nums.size();
        vector<int> memo(size, -1);
        return backtrack(0, 0, nums, memo);
    }
};