#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int memo[n][2];
        memo[0][0] = 0;
        memo[0][1] = 1;
        for(int i = 1; i < n; i++) {
            int swapped = 1e7, notswapped = 1e7;
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1])  {
                notswapped = min(notswapped, memo[i-1][0]);
                swapped = min(swapped, memo[i-1][1]+1);
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                swapped = min(swapped, memo[i-1][0]+1);
                notswapped = min(notswapped, memo[i-1][1]);
            }
            memo[i][0] = notswapped;
            memo[i][1] = swapped;
        }
        return min(memo[n-1][0], memo[n-1][1]);
    }
};
