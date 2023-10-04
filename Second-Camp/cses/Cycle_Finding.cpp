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
typedef tuple<ll, ll, ll> tll;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for (ll i = 0; i < n; ++i)
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
#define INF_LL 1LL<<62

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */
template <typename T>
void display(vector<T> &arr) {
    for (auto &i : arr) cout << i << " ";
    cout << endl;
}

void bellman(int n, vector<tll>& edges) {
    vl dist(n+1, INF_LL), parent(n+1);
    parent[0] = 0;
    dist[1] = 0;
    ll check = 0;
    FOR(_, n) {
      check = 0;
        for(auto [from, to, weight] : edges) {
            if (dist[from]+weight < dist[to]) {
                dist[to] = dist[from] + weight;
                parent[to] = from;
                check = from;
            }
        }
    }
    if (!check) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    FOR(i, n+1) check = parent[check];
    vl cycle;
    for(ll x = check;; x=parent[x]){
      cycle.pb(x);
      if (x == check && cycle.size() > 1) break;
    }
    reverse(all(cycle));
    display(cycle);
}

// Main function for solving the problem
void solve() {
    // Start here
    int n, m;
    cin >> n >> m;
    vector<tll>edges;
    FOR(_, m) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({a, b, w});
    }
    bellman(n, edges);
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}