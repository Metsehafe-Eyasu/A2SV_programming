#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int feasible(int val, int size, vector<int>& nums) {
        int right = val+size-1;
        int diff = upper_bound(nums.begin(), nums.end(), right) - lower_bound(nums.begin(), nums.end(), val);
        return size - diff;
    }
    int minOperations(vector<int>& nums) {
        int min_ = INT_MAX;
        int size = nums.size();
        set<int>a(nums.begin(), nums.end());
        vector<int>arr(a.begin(), a.end());
        for(int num: arr) {
            min_ = min(min_, feasible(num, size, arr));
        }
        return min_;
    }
};
