#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int memo[20];
    int numTrees(int n) {
        if (n <= 1) return 1;
        if (!memo[n]) 
            for(int i = 1; i <= n; i++) 
                memo[n] += numTrees(i-1) * numTrees(n-i);
        return memo[n];
    }
};
