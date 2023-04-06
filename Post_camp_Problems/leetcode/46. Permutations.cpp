#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int used = 0;
    vector<vector<int>>answer;

    void backtrack(vector<int>& path, vector<int>& nums) {
        if (path.size() == nums.size()){
            answer.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if ( (used & (1 << i)) == 0) {
                used |= (1 << i);
                path.push_back(nums[i]);
                backtrack(path, nums);
                path.pop_back();
                used ^= (1 << i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(vector<int>{}, nums);
        return answer;
    }
};