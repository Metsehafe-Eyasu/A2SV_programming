#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int mod = 1e9 + 7;
        const int p = 31;
        const int h = haystack.size(), n = needle.size();
        vector<long long> ppows(max(h,n), 1);
        for (int i = 1; i < h; i++) 
            ppows[i] = (ppows[i - 1] * p) % mod;
        vector<long long> hHash(h + 1, 0);
        for (int i = 0; i < h; i++) 
            hHash[i + 1] = (hHash[i] + (haystack[i] - 'a') * ppows[i]) % mod;
        long long needleHash = 0;
        for (int i = 0; i < n; i++) needleHash = (needleHash + (needle[i] - 'a') * ppows[i]) % mod;

        for (int i = 0; i + n - 1 < h; i++)
        {
            long long windowHash = (hHash[i + n] + mod - hHash[i]) % mod; 
            if ((ppows[i] * needleHash) % mod == windowHash && haystack.substr(i, n) == needle) return i;
        }

        return -1;
    }
};
