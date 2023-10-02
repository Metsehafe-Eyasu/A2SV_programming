#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> arr;
        for (char ch: s) {
            if(arr.empty() || arr.back().first != ch) {
                arr.push_back({ch, 1});
            } else {
                int count = arr.back().second+1;
                arr.pop_back();
                arr.push_back({ch, count});
            }
            if (arr.back().second == k) arr.pop_back();
        }
        string ans = "";
        for(auto [ch, count]: arr) {
            for(int i=0;i<count;i++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};