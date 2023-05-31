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
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

// unordered_map<pair<int, bool>, int, hash_pair>memo;
vector<vector<int>> memo(101, vector<int>(2, -1));

int dp (int curr, bool contain, int k, int d) {
    if (curr <= 0)
        return int(contain && curr == 0);

    if (memo[curr][int(contain)] == -1) {
        ll sum_ = 0;
        for(int i = 1; i <= k; i++) {
            bool temp = (contain || i >= d);
            sum_ += dp(curr - i, temp, k, d);
        }
        memo[curr][int(contain)] = sum_%MOD;
    }   
    return memo[curr][int(contain)]; 
}

// Main function for solving the problem
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    cout << dp(n, false, k, d) << endl;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
