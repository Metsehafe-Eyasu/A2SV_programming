#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int>stack;
        int currNum = 0;
        char oper = '+';
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            if (isdigit(currChar)) currNum = (currNum*10) + (s[i]-'0');
            if (!isdigit(currChar) && !iswspace(currChar) || i == n-1) {
                if (oper == '-') stack.push_back(-currNum);
                else if (oper == '+') stack.push_back(currNum);
                else if (oper == '*') {
                    int num = stack.back(); stack.pop_back();
                    stack.push_back(num*currNum);
                } else if (oper == '/') {
                    int num = stack.back(); stack.pop_back();
                    stack.push_back(num/currNum);
                }
                currNum = 0;
                oper = currChar;
            }
        }
        int answer = accumulate(stack.begin(), stack.end(), 0);
        return answer;
    }
};