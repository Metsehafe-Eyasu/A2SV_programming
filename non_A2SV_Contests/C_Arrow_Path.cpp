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

bool inbound(int x, int y, int len) {
    if (x >= 0 && x < 2 && y >= 0 && y < len) return true;
    return false;
}

// Main function for solving the problem
void solve() {
    // Start here
    int n;
    cin >> n;
    vs grid;
    IL(grid, 2);
    
    queue<pii> bfs;
    bfs.push({0,0});
    
    set<pii> visited;
    visited.insert({0,0});

    int dirs[] = {-1, 0, 1, 0, -1};
    while(!bfs.empty()) {
        pii curr = bfs.front();
        bfs.pop();
        if (curr == pii(1, n-1)) {
            cout << "YES\n";
            return;
        }

        FOR(i, 4) {
            int nx = dirs[i] + curr.first;
            int ny = dirs[i+1] + curr.second;
            if(!inbound(nx, ny, n)) continue;

            if (grid[nx][ny] == '<') ny--;
            else ny++;
            if (visited.find(mp(nx, ny)) == visited.end()) {
                bfs.push({nx, ny});
                visited.insert({nx, ny});
            }
        }
    }
    cout << "NO\n";
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}