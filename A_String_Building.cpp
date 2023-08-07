#include <bits/stdc++.h>
using namespace std;

// Shorthand notations
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef set<int> si;
typedef set<ll> sl;
typedef priority_queue<int, vector<int>, greater<int>> min_pq;
typedef priority_queue<int> max_pq;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORR(i, n) for (int i = n - 1; i >= 0; --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define forRange(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

template <typename T>
void inputList(vector<T> &arr, int n) {
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

vector<int>memo;

bool dp(int index, string&s, vector<string>& wordDict) {
    if (index < 0) return true;
    if (memo[index] != -1) return memo[index] == 1;
    for(string word: wordDict) {
        int currWordSize = word.size();
        if (index - currWordSize + 1 >= 0) {
            if (s.substr(index - currWordSize + 1, currWordSize) == word && dp(index - currWordSize, s, wordDict)) {
                memo[index] = 1;
                return true;
            }
        } 
    }
    memo[index] = 0;
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    memo = vector(s.length(), -1);
    return dp(s.length() - 1, s, wordDict);
}

// Main function for solving the problem
void solve() {
    // Start here
    vector<string> usableWords{"aa", "aaa", "bb", "bbb"};
    string s;
    cin >> s;
    if (wordBreak(s, usableWords))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}