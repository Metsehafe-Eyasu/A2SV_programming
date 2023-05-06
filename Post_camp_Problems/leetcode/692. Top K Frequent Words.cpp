#include <bits/stdc++.h>
using namespace std;
struct lambda {
    bool operator()(pair<string, int>& a, pair<string, int>& b){
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }  
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for(auto& a: words) hash[a]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, lambda>pq;
        for(auto& [key, val] : hash) {
            pq.push(make_pair(key, val));
            if (pq.size() > k) pq.pop();
        }

        vector<string>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};