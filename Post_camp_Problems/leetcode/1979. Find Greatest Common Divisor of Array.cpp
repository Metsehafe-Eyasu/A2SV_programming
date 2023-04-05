#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int mini = 1001, maxi = 0;
        for (auto&a: nums) {
            mini = min(mini, a);
            maxi = max(maxi, a);
        }
        return GCD(maxi, mini);
    }
};