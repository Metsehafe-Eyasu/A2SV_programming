class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        unordered_map<int, unordered_map<int, bool>>memo;
        function<bool(int, int)> dp = [&](int i, int j) {
            bool ans = false;
            if (!memo.count(i) || !memo[i].count(j)) {
                if (j == m) ans = bool(i == n);
                else {
                  bool match = (i < n) && (p[j] == s[i] || p[j] == '.');
                  if (j+1 < m && p[j+1] == '*') 
                    ans = dp(i, j+2) || (match && dp(i+1, j));
                  else 
                    ans = match && dp(i+1, j+1);
                }
              memo[i][j] = ans;
            }
            return memo[i][j];
        }; 
      return dp(0, 0);
    }
};