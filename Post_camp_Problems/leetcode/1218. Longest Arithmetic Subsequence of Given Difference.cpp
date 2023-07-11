#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int>memo;
        int max_ = 0;
        for(int cur: arr) {
            memo[cur] = memo[cur - difference] + 1;
            max_ = max(max_, memo[cur]);
        }
        return max_;
    }
};