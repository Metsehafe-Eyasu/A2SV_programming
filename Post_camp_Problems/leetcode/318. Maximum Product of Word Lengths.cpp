#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int converter(string& a) {
        int x = 0;
        for (auto& c: a) {
            x |= (1 << (c - 'a'));
        }
        return x;
    }
    int maxProduct(vector<string>& words) {
        vector<int> strtobit(words.size());
        int placer = 0;
        for (auto& a: words) {
            strtobit[placer++] = converter(a);
        }
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size();j++) {
                if ((strtobit[i] | strtobit[j]) == strtobit[i] + strtobit[j]) {
                    int currlen = (words[i].length() * words[j].length());
                    count= max(count, currlen);
                }

            }
        }
        return count;
    }
};