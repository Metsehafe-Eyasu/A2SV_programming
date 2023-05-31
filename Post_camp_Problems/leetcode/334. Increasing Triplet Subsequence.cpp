#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (auto&a: nums) {
            if (a < first) first = a;
            if (a > first && a < second) second = a;
            if (a > second) return true;
        }
        return false;
    }
};