#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long window = 0, index = 0, pow = 1, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            window = (window * power + s[i] - 'a' + 1) % modulo;
            if (i + k >= n) pow = (pow*power) % modulo;
            else window = (window - (s[i + k] - 'a' + 1) * pow % modulo + modulo) % modulo;
            
            if (window == hashValue) index = i;
        }
        return s.substr(index, k);
    }
};