#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() == 1) return false;
        unordered_map<int, int> counter;
        for(auto& card: deck) {
            counter[card]++;
        }

        int minEl = INT_MAX;
        for(auto& [key, val] : counter) {
            cout << key << " " << val << endl;
            minEl = min(minEl, val);
        }
        for(auto& [key, val] : counter) {
            minEl = GCD(val, minEl);
            if (minEl == 1)
                return false;
        }
        return true;
    }
};