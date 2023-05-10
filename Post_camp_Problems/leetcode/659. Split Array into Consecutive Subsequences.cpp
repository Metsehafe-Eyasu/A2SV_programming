#include <bits/stdc++.h>
using namespace std;
struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a.size() > b.size();
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) return false;
        unordered_map<int, priority_queue<vector<int>, vector<vector<int>>, Compare>> subsequences;

        for (int num : nums) {
            if (subsequences[num - 1].empty()) {
                subsequences[num].push({num});
            } else {
                vector<int> seq = subsequences[num - 1].top();
                subsequences[num - 1].pop();
                seq.push_back(num);
                subsequences[num].push(seq);
            }
        }
        for (auto& entry : subsequences) {
            while (!entry.second.empty()) {
                if (entry.second.top().size() < 3) return false;
                entry.second.pop();
            }
        }

        return true;
    }
};