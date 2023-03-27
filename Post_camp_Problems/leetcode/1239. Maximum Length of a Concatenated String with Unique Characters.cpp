#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, int> path;
    int length = 0;
    int maxLen = 0;
    void backtrack(vector<string>& arr, int index) {
        if (index >= arr.size()) 
            return;
        bool check = true;
        for (char c: arr[index]) {
            length++;
            if (path[c]++ >= 1) 
            check = false;
        }
        if (check) {
            maxLen = max(maxLen, length);
            backtrack(arr, index + 1);
        }
        for (char c: arr[index]) {
            length--;
            path[c]--;
            if (path[c] == 0)
                path.erase(c);
        } 
        backtrack(arr, index + 1);

    }
public:
    int maxLength(vector<string>& arr) {
        backtrack(arr, 0);
        return maxLen;
    }
};