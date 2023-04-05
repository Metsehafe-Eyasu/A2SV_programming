#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = (x ^ y);
        int count = 0;
        long long a = 1;
        while (a <= n) {
            if ((a & n) >= 1) count++;
            a <<= 1;
        }    
        return count;   
    }
};