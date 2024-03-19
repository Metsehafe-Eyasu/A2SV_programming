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
    int n, target;
    cin >> n >> target;
    vi arr;
    IL(arr, n);
    int l = 0, r = n;
    int index = find(all(arr), target) - arr.begin();
    bool seen = false;
    while (l + 1 < r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == target) seen = true;
        if (arr[mid] <= target) l = mid;
        else r = mid;
    }
    if (arr[l] == target) {
        cout << 0 << endl;
        return;
    } 
    if(!seen || arr[l] < target) {
        cout << 1 << endl;
        cout << l + 1 << " " << index + 1 << endl;
        return;
    }
    swap(arr[l], arr[target]);
    cout << 2 << endl;
    cout << l + 1 << " " << index + 1 << endl;

    index = l;
    l = 0, r = n;
    while (l + 1 < r) {
        int mid = l + (r-l)/2;
        if (arr[mid] <= target) l = mid;
        else r = mid;
    }
    cout << l + 1 << " " << index + 1 << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}