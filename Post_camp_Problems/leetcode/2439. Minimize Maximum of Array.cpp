#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int answer = 0;
        long long sum_ = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum_ += nums[i];
            answer = max(answer, int((sum_ + i) / (i + 1)));
        }
        
        return answer;
    }
};