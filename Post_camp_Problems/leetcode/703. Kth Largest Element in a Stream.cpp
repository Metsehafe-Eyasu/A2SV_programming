#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxLen;
    KthLargest(int k, vector<int>& nums) {
        maxLen = k;
        for(auto&a: nums) {
            pq.push(a);
            if (pq.size() > maxLen) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > maxLen) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */