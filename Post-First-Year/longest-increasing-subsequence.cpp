class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n, 0);
        for(int i = 0; i < n; i++) {
            memo[i] = 1;
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) memo[i] = max(memo[i], memo[j] + 1);
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};