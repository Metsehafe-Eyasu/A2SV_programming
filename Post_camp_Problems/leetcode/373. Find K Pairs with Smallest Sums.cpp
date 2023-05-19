#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<tup, vector<tup>, greater<tup>>pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>>ans;
        while(k-- && !pq.empty()) {
            auto [sum_, ind1, ind2] = pq.top();
            pq.pop();
            ans.push_back({nums1[ind1], nums2[ind2]});
            if (ind2 < nums2.size() - 1) {
                pq.push({nums1[ind1] + nums2[ind2 + 1], ind1, ind2 + 1});
            }
        }
        return ans;
    }
};