#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long MOD = 1e9 + 7;
    int factorial(int n) {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }
    int pow(long long base, int exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    int countOrders(int n) {
        int twoNFact = factorial(2 * n) % MOD;
        int twoPowN = pow(2, n, MOD);
        return (1LL * twoNFact * pow(twoPowN, MOD - 2, MOD)) % MOD;    
    }
};