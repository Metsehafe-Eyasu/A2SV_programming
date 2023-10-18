#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod_exp(long long x, long long y, long long m) {
        long long res = 1;
        while (y > 0) {
            if (y & 1) res = (res * x) % m;
            x = (x * x) % m;
            y >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long MOD = 1e9+7;
        long long ans = 1;
        if (n/2 > 0) ans *= mod_exp(4, n/2, MOD);
        ans = (ans * mod_exp(5, n - (n/2), MOD))%MOD;
        return (int)ans;
    }
};