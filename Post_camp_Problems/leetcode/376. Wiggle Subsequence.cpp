#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo;
        for(int i = 1 ; i < n ; i++) {
            int diff = nums[i] - nums[i-1];
            if (diff != 0) memo.push_back(diff);
        }
        if (memo.empty()) return 1;
        int ans = 2;
        n = memo.size();
        for(int i = 1; i < n; i++) {
            if ((memo[i] > 0 && memo[i-1] < 0) || (memo[i] < 0 && memo[i-1] > 0))
                ans++;
        }
        return ans;
    }
};
