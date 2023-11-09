class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>stack;
        int max_val = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < max_val) return true;
            while(!stack.empty() && stack.back() < nums[i]) {max_val = stack.back(); stack.pop_back();}
            stack.push_back(nums[i]); 
        }
        return false;
    }
};