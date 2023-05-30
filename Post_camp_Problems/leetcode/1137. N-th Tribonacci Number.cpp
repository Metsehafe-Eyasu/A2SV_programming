#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int>memo;
    int tribonacci(int n) {
        if (n < 2) return n;
        if (n == 2) return 1;
        if (!memo[n]) memo[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        return memo[n];
    }
};