#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int currSum = 0;
        int totalSum = 0;
        for (int i = satisfaction.size() - 1; i > -1 && currSum + satisfaction[i] > 0; --i) {
            currSum += satisfaction[i];
            totalSum += currSum;
        }
        return totalSum;
    }
};