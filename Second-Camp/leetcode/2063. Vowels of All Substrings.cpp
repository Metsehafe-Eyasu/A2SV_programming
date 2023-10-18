#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        int n = word.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if (vowels.count(word[i])) ans += (long long)(i+1LL)*(n-i);
        }
        return ans;
    }
};