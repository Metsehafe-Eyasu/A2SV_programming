#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> builder(string s) {
        int n = s.size(), j = 0, i = 1;
        vector<int>arr(n, 0);
        while(i < n) {
            if (s[i] == s[j]) arr[i++] = ++j;
            else {
                if (j > 0) j = arr[j-1];
                else i++;
            }
        }
        return arr;
    }
    int repeatedStringMatch(string a, string b) {
        vector<int>lps = builder(b);
        int i = 0;
        int len =  3 * (max(a.size(), b.size())/min(a.size(), b.size()));
        for(int k = 1; k <= len; k++) {
            int j = 0;
            while (j < a.size()) {
                if (a[j] == b[i]) {i++; j++;}
                else {
                    if (i == 0) j++;
                    else i = lps[i-1];
                }
                if (i == b.size()) return k;
            }
        }
        return -1;
    }
};
