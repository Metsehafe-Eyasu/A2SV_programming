#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a%b);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            for(int j = i; j < n; j++) {
                curr = GCD(curr, nums[j]);
                if (curr == k) ans++;
                else if (curr < k) break;
            }
        }
        return ans;
    }
};