#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long k = 1;
        int check = (n & k);
        while(k <= n) {
            if ((check == 0 && (n & k) != 0) || (check == 1 && (n & k) == 0))
                return false;
            k <<= 1;
            check ^= 1;
        }
        return true;
    }
};