#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>memo(n+1, 0);
        memo[n] = 1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] != '0') 
                memo[i] += memo[i+1];
            if (i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) 
                memo[i] += memo[i+2];
        }
        return memo[0];
    }
};
