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
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef set<int> si;
typedef set<ll> sl;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template<typename Key1, typename Key2, typename Value>
using umumap = unordered_map<Key1, unordered_map<Key2, Value>>;
template<typename T>
using vv = vector<vector<T>>;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORR(i, n) for (int i = n - 1; i >= 0; --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define forRange(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

void YES() {
    cout << "YES\n";
}
void NO() {
    cout << "NO\n";
}

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

template <typename T>
void display(vector<T> &arr) {
    for (auto &i : arr) cout << i << " ";
    cout << endl;
}

template <typename T>
void IL(vector<T> &arr, int n) {
    arr.resize(n);
    for (auto &a : arr) cin >> a;
}

ll mod_exp(ll x, ll y, ll m) {
    x%=m;
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

// Main function for solving the problem
void solve() {
    // Start here
    int n, k;
    cin >> n >> k;
    vl nums;
    IL(nums, n);
    ll total = 0;
    ll max_ = 0;
    ll min_ = 0;
    for(int num: nums){
        total += num;
        max_ = max(total - min_, max_);
        min_ = min(min_, total);
    }
    ll res = mod_exp(2, k, MOD);
    total += max_*(res - 1);
    total = (total%MOD + MOD) % MOD;
    cout << total << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}