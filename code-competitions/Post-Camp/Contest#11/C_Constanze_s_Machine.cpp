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
#define fast_io ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
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
void inputList(vector<T> &arr, int n)
{
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

unordered_map<ll, ll> memo;
ll fib(ll n) {
    if (n == 0 || n == 1) return n;
    if (!memo[n]) 
        memo[n] = (fib(n-1)%MOD + fib(n-2)%MOD)%MOD;
    return memo[n];
}

// Main function for solving the problem
void solve()
{
    // Start here
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 1;
    if (s[0] == 'm' || s[0] == 'w') {
        std::cout << 0 << endl;
        return;
    }
    forRange(i, 1, n-1) {
        if (s[i] == 'm' || s[i] == 'w') {
            std::cout << 0 << endl;
            return;
        }
        int count = 1;
        while((s[i] == 'n' || s[i] == 'u') && s[i] == s[i-1]) {
            count++;
            i++;
        }
        if (count > 1) {
            ans = (ans* fib(count+1))%MOD;
        }
    }
    cout << ans << endl;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}