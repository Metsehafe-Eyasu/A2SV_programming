#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = 0;
            for(long from = (long)curr, to = (long)curr+1; from <= n; from*=10, to*=10){
                steps += min((long)n + 1, to) - from;
            }
            if (steps <= k) {
                curr++;
                k-=steps;
            } else  {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};