#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    int curr = pq.top();
                    pq.pop();
                    if (curr <= bricks) {
                        bricks -= curr;
                    } else {
                        return ans;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};