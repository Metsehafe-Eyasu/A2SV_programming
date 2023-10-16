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

// Main function for solving the problem
void solve() {
    // Start here
    int n, m;
    cin >> n >> m;
    vvi graph(n+m);
    vpii band(n+m, {0, 0});
    queue<int>q;
    FOR(i, n) {
        int cap, ban;
        cin >> cap >> ban;
        band[i] = {cap, ban};
        q.push(i);
    }
    forRange(i, n, m+n-1) {
        int cap, par;
        cin >> cap >> par;
        graph[par].pb(i);
        band[par].first--;
        band[i].first += cap;
    }
    int ans = -1;
    int val = -1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int c = sz(graph[curr]);
        int bnd = band[curr].second ;
        if (band[curr].first > 0 && ans <= (bnd/(c+1))) {
            ans = bnd/(c+1);
            val = curr;
        } 
        for(int next: graph[curr]) {
            band[next].second = bnd/c;
            q.push(next);
        }
    }
    cout << val << endl;
}

int main() {
    fast_io;
    solve();
    return 0;
}