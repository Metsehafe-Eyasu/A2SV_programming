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

// Main function for solving the problem
void solve() {
    // Start here
    int n, m;
    cin >> n >> m;
    vector<vpii> graph(n+1);
    FOR(_, m) {
      int a, b, w;
      cin >> a >> b >> w;
      graph[a].pb({b, w});
      graph[b].pb({a, w});
    }
    vector<bool>visited(n+1, false);
    vl distances(n+1, INT_MAX), parent(n+1, -1);
    distances[1] = 0;
    visited[1]=true;
    priority_queue<pii, vpii, greater<>>pq;
    pq.emplace(0, 1);
    while(!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        visited[node]=true;
        if (node == n) break;
        for(auto [to, weight] : graph[node]) {
            int next = dist + weight;
            if (!visited[to] && next < distances[to]) {
              pq.emplace(next, to);
              distances[to] = next;
              parent[to] = node;
            }
        }
    }
    if (parent[n] == -1) {
      cout << -1 << endl;
      return;
    }
    vi ans{n};
    int i = n;
    while(i != 1) {
      i = parent[i];
      ans.pb(i);
    }
    FORR(i, ans.size()) {
      cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}