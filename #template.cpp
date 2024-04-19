#include <bits/stdc++.h>
using namespace std;

// Shorthand notations
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;

template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_pq = priority_queue<T>;
template<typename Key, typename Value> using umap = unordered_map<Key, Value>;
template<typename Key1, typename Key2, typename Value> using umumap = unordered_map<Key1, unordered_map<Key2, Value>>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using v = vector<T>;

// Macros
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORR(i, n) for (int i = n - 1; i >= 0; --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define forRange(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MOD 1'000'000'007

void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

template <typename T> void display(vector<T> &arr) { for (auto &i : arr) cout << i << " "; cout << endl; }
template <typename T> void IL(vector<T> &arr, int n) { arr.resize(n); for (auto &a : arr) cin >> a; }

/**
 * @author ThePhenom-Pro
 */


// Main function for solving the problem
void solve() {
    // Start here

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}