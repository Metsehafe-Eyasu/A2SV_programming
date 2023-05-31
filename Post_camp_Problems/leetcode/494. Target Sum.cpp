#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, hash_pair>memo;
    int solve(int index, int target, vector<int>&nums) {
        if (index >= nums.size())
            return int(target == 0);
        
        if (!memo.count({index, target})) {
            memo[{index, target}] = solve(index+1, target+nums[index], nums) + solve(index+1, target-nums[index], nums);
        }
        return memo[{index, target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};