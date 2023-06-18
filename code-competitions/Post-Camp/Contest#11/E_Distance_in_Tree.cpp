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

vvi memo(50001, vi(501, 0));
int ans = 0;

void dfs(int curr, int k, vvi& arr, int parent) {
    memo[curr][0] = 1; 
    for (int neighbor : arr[curr]) {
        if (neighbor != parent) {
            dfs(neighbor, k, arr, curr);
            for (int j = 1; j <= k; j++)
                ans += memo[neighbor][j - 1] * memo[curr][k - j];
            for (int j = 1; j <= k; j++)
                memo[curr][j] += memo[neighbor][j - 1];
        }
    }
}

// Main function for solving the problem
void solve()
{
    int n, k;
    cin >> n >> k;
    vvi arr(n+1);
    FOR(_, n-1) {
        int a, b;
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    dfs(1, k, arr, 0);
    std::cout << ans << endl;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}