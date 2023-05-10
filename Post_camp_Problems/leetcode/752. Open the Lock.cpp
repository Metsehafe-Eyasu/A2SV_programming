#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        int ans = 0;
        queue<string>q;
        q.push("0000");
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                string s = q.front();
                q.pop();
                cout << s << endl;
                if (s == target) return ans;
                for(int j = 0; j < 4; j++) {
                    string fwd = s.substr(0, j) + to_string(s[j] == '0' ? 9 : s[j] - '0' - 1) + s.substr(j+1);
                    string bwd = s.substr(0, j) + to_string(s[j] == '9' ? 0 : s[j] - '0' + 1) + s.substr(j+1);
                    if (!visited.count(fwd)) {
                        visited.insert(fwd);
                        q.push(fwd);
                    }
                    if (!visited.count(bwd)) {
                        visited.insert(bwd);
                        q.push(bwd);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};