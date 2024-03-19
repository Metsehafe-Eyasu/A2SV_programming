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

// Main function for solving the problem
void solve() {
    // Start here
    int n, k;
    cin >> n >> k;
    vi arr;
    IL(arr, 2*n);
    map<int, int> left, right;
    FOR(i, n) {
        left[arr[i]]++;
        right[arr[i+n]]++;
    }
    vi l, r;
    vpii temp1, temp2;
    for(auto [key, val]: left) temp1.pb({val, key});
    sort(rall(temp1));
    for(auto [val, key]: temp1) {
        if(l.size() == 2*k) break;
        if(val == 2 && l.size() + 2 <= 2*k){
            l.pb(key);
            l.pb(key);
        } else if (val == 1){
            l.pb(key);
            r.pb(key);
        }
    }
    for(auto [key, val]: right) temp2.pb({val, key});
    sort(rall(temp2));
    for(auto [val, key]: temp2) {
        if(r.size() == 2*k) break;
        if(val == 2 && r.size() + 2 <= 2*k){
            r.pb(key);
            r.pb(key);
        }
    }
    display(l);
    display(r);
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}