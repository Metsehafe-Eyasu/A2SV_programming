#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long n = 1;
        while (n <= num) n <<= 1;
        return (num ^ (n - 1));
    }
};