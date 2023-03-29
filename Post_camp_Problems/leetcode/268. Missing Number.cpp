#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            while (nums[i] != i && nums[i] != length) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < length; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return length;
    }
};