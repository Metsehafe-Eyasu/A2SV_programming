#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>>memo;
    int recursive(int index, int sum_, vector<int>& stones) {
        if (index == stones.size()) return abs(sum_);
        if (!(memo.count(index) && memo[index].count(sum_))) {
            memo[index][sum_] = min(
                recursive(index+1, sum_ + stones[index], stones), 
                recursive(index+1, sum_ - stones[index], stones)
            );
        }
        return memo[index][sum_];
    }
    int lastStoneWeightII(vector<int>& stones) {
        return recursive(0, 0, stones);
    }
};