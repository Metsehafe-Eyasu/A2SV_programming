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
void display(vector<T> &arr) {
    for (auto &i : arr) cout << i << " ";
    cout << endl;
}

template <typename T>
void inputList(vector<T> &arr, int n) {
    arr.resize(n);
    for (auto &a : arr) cin >> a;
}

int feasible(int index, int k, vi& arr) {
    int count = 1;
    FORR(i, index) {
      int diff = arr[index] - arr[i];
      k -= diff;
      if (k < 0) break;
      count++;
    }
    return count;
}

// Main function for solving the problem
void solve() {
    // Start here
    int n, k;
    cin >> n >> k;
    vi arr;
    inputList(arr, n);
    sort(all(arr));
    int max_ = 1, val = arr[0];
    int left = 0, right = n-1;
    while (left < right) {
        int mid = left + (right - left)/2;
        mid = upper_bound(all(arr), arr[mid]) - arr.begin() - 1;
        int count = feasible(mid, k, arr);
        if(count > max_) {
          left = mid+1;
          max_ = count;
          val = arr[mid];
        }
        else right = mid;
    }
    cout << max_ << " " << val << endl;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}