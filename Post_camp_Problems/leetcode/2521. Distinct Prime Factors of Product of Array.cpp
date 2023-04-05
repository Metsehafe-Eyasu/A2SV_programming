#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> hash;
    void factorize(int n) {
        int d = 2;
        while (d*d <= n) {
            while (n%d == 0) {
                hash[d]++;
                n/=d; 
            }
            d++;
        }
        if (n > 1) hash[n]++;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for(auto& a: nums) {
            factorize(a);
        }
        return hash.size();
    }
};