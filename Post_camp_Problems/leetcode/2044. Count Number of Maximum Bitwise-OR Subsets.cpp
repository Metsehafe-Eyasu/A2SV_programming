#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> subarrays;
    vector<int> path;
    int calculate()
    {
        int a = 0;
        for (auto &c : path)
        {
            a |= c;
        }
        return a;
    }
    void backtrack(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            subarrays.push_back(calculate());
            return;
        }

        path.push_back(nums[index]);
        backtrack(nums, index + 1);
        path.pop_back();
        backtrack(nums, index + 1);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        int m = *max_element(subarrays.begin(), subarrays.end());

        int count = 0;
        for (auto &a : subarrays)
        {
            if (a == m)
                count++;
        }
        return count;
    }
};