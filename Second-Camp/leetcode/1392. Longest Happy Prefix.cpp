#include <bits/stdc++/h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), j = 0, i = 1;
        vector<int>arr(n, 0);
        while(i < n) {
            if (s[i] == s[j]) arr[i++] = ++j;
            else {
                if (j > 0) j = arr[j-1];
                else i++;
            }
        }
        int size = arr[n-1]; 
        return s.substr(0, size);
    }
};
