#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for(int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    int kthNum(vector<int>& nums, int l, int r, int k) {
        int index = partition(nums, l, r);
        if (index - l == k - 1)
            return nums[index];

        if (index - l > k - 1)
            return kthNum(nums, l, index - 1, k);
        return kthNum(nums, index + 1, r, k - index + l - 1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int revK = nums.size() - k + 1;
        return kthNum(nums, 0, nums.size() - 1, revK);
    }
};