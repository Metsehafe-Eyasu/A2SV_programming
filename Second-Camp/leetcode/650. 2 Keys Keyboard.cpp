#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int d = 2;
        int ans = 0;
        while (d*d <= n) {
            while (n%d == 0) {
                ans += d;
                n/=d; 
            }
            d++;
        }
        if (n > 1) ans+= n;
        return ans;
    }
};