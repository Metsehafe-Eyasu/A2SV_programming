#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            while (nums[i] - 1 != i && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> answer;
        for (int i = 0; i < length; i++) {
            if (nums[i] - 1 != i) {
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};