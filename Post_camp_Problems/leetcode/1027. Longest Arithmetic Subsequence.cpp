#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int>> memo(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                int x = nums[i] - nums[j];
                if (memo[j][x] == NULL)
                    memo[i][x] = 2;
                else
                    memo[i][x] = memo[j][x] + 1;
            }
        }

        int max_ = 0;
        for(auto& a: memo)
            for(auto&[b, c]: a)
                max_ = max(max_, c);
        return max_;
    }
};
