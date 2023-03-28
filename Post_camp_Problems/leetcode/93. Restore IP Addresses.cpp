#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> answer;

    bool check(string& a) {
        int conv = stoi(a);
        if (conv <= 255 && (a.length() == 1 || a[0] !='0'))
            return true;
        return false;
    }

    string converter(vector<string>& arr) {
        string ip;
        for (int i = 0; i < arr.size(); i++) {
            if (i != arr.size() - 1)
                ip += (arr[i] + '.');
            else
                ip += arr[i];
        }
        return ip;
    }

    void backtrack(string& s, vector<string>& st, int index) {
        if (st.size() == 4){
            string IP = converter(st);
            if (IP.size() == s.length() + 3)
                answer.push_back(IP);
            return;
        }

        for (int i = index + 1; i < index + 4; i++) {
            if (i > s.length())
                return;
            string part = s.substr(index, i - index);
            if (check(part)){
                st.push_back(part);
                backtrack(s, st, i);
                st.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> st;
        backtrack(s, st, 0);
        return answer;
    }
};