#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >=0 ; --i) {
            int count = 0;
            for(auto&a: nums) {
                if (a & (1 << i)) count++;
            }

            if (count % 3) ans |= (1 << i);
        }

        return ans;
    }
};