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

vvi dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

bool inBound(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j < m && j >= 0) return true;
    return false;
}

// Main function for solving the problem
void solve() {
    // Start here
    int n, m;
    cin >> n >> m;
    vs grid;
    inputList(grid, n);
    vvi numGrid(n, vi(m, 0));
    int x = 1;
    FOR(i, n) {
        FOR(j, m) {
            if (grid[i][j] == '*') {
                vpii adjx, adjy;
                if (i > 0 && grid[i-1][j] == '*')
                    adjx.emplace_back(i-1, j);
                if (i < n-1 && grid[i+1][j] == '*')
                    adjx.emplace_back(i+1, j);
                if (j > 0 && grid[i][j-1] == '*')
                    adjy.emplace_back(i, j-1);
                if (j < m-1 && grid[i][j+1] == '*')
                    adjy.emplace_back(i, j+1);

                if (sz(adjx)== 1 && sz(adjy) == 1) {
                    if (numGrid[i][j] != 0) { cout << "NO\n"; return; }
                    if (numGrid[adjx[0].first][adjx[0].second] != 0) { cout << "NO\n"; return; }
                    if (numGrid[adjy[0].first][adjy[0].second] != 0) { cout << "NO\n"; return; }
                    numGrid[i][j] = x;
                    numGrid[adjx[0].first][adjx[0].second] = x;
                    numGrid[adjy[0].first][adjy[0].second] = x++;
                } else if (max(sz(adjx), sz(adjy)) > 2) { cout << "NO\n"; return; }
            }
        }
    }
    FOR(i, n) {
        FOR(j, m) {
            if (grid[i][j] == '*'){
                if (numGrid[i][j] == 0) { cout << "NO\n"; return; }
                FOR(k, 8) {
                    int nx = i + dirs[k][0];
                    int ny = j + dirs[k][1];
                    if (inBound(nx, ny, n, m) && numGrid[nx][ny] != 0 && numGrid[nx][ny] != numGrid[i][j]){ 
                        cout << "NO\n"; 
                        return; 
                    }
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}