class Solution {
    vector<int> path;
    set<vector<int>> answer;
public:
    void backtrack(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return;
        }
        if (path.empty() || path.back() <= nums[index]) {
            path.push_back(nums[index]);
            if (path.size() >= 2)
                answer.insert(path);
            backtrack(nums, index + 1);
            path.pop_back();
        }
        backtrack(nums, index + 1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        vector<vector<int>> ans;
        for (auto i: answer) {
            ans.push_back(i);
        }
        return ans;
    }
};