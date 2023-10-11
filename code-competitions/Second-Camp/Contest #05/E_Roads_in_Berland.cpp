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

int calc(vvi &grid) {
  int ans = 0;
  FOR(i, grid.size()) {
    forRange(j, i+1, grid.size()-1) {
      ans+= grid[i][j];
    }
  }
  return ans;
}

// Main function for solving the problem
void solve() {
    // Start here
    int n, k;
    cin >> n;
    vvi grid(n);
    FOR(i, n) inputList(grid[i], n);
    cin >> k;
    int sum_ = calc(grid); 
    FOR(_, k) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        if (grid[from][to] > weight) {
          grid[from][to] = weight;
          grid[to][from] = weight;
          int l = from;
          for(int i = 0; i < n; i++) 
              for(int j = 0; j < n; j++) 
                  grid[i][j] = min((long)grid[i][j], (long)grid[i][l] + (long)grid[l][j]);
          l = to;
          for(int i = 0; i < n; i++) 
              for(int j = 0; j < n; j++) 
                  grid[i][j] = min((long)grid[i][j], (long)grid[i][l] + (long)grid[l][j]);
          sum_ = calc(grid);
        }
      cout << sum_ << " ";
    }
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}