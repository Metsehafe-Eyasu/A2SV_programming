class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>memo;
        for(int i = 0; i < nums.size(); i++) {
            if (memo.count(target - nums[i])) return {i, memo[target-nums[i]]};
            memo[nums[i]] = i;
        }
        return {0, 1};
    }
};