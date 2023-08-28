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

struct UnionFind
{
    vector<ll> parent, size;
    UnionFind(ll n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    ll findSize(ll x) {
        return size[find(x)];
    }
    bool isConnected(ll x, ll y) {
        return find(x) == find(y);
    }
    bool unite(ll x, ll y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

template <typename T>
void inputList(vector<T> &arr, int n) {
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

bool inBound(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j < m && j >= 0) return true;
    return false;
}
vvi dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void dfs(int i, int j, vs& grid, UnionFind& uf, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    int n = grid.size(), m = grid[0].size();
    FOR(k, 4) {
        int nx = i + dirs[k][0];
        int ny = j + dirs[k][1];
        if (inBound(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == '.'){
            uf.unite(i*m + j, nx*m + ny);
            dfs(nx, ny, grid, uf, visited);
        }
    }
}

// Main function for solving the problem
void solve() {
    // Start here
    ll n, m;
    cin >> n >> m;
    vs grid(n);
    inputList(grid, n);
    UnionFind uf(n*m+1);
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    FOR(i, n) 
        FOR(j, m) 
            if (!visited[i][j] && grid[i][j] == '.')
                dfs(i, j, grid, uf, visited);
                
    FOR(i, n) {
        FOR(j, m) {
            if (grid[i][j] != '.') {
                set<int> parent;
                FOR(k, 4) {
                    int nx = i + dirs[k][0];
                    int ny = j + dirs[k][1];
                    if (inBound(nx, ny, n, m) && grid[nx][ny] == '.'){
                        parent.insert(uf.find(nx*m + ny));
                    }
                }
                int ans = 1;
                for(int par: parent) 
                    ans += uf.findSize(par); 
                ans %= 10;
                cout << ans;
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}