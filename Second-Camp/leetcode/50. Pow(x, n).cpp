#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n < 0) return 1/(x*myPow(x, abs(n)-1));
        else {
            if (n%2) return x*myPow(x*x, n/2);
            return myPow(x*x, n/2);
        }
    }
};