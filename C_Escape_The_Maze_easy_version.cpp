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
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
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
void inputList(vector<T> &arr, int n)
{
  arr.resize(n);
  for (auto &a : arr)
    cin >> a;
}

// Main function for solving the problem
bool solve()
{
  // Start here
  int n, k;
  cin >> n >> k;
  vi color(n, -1);
  queue<int> q;
  FOR(i, k){
    int c;
    cin >> c;
    color[--c] = 0;
    q.push(c);
  }
  vector<vector<int>> graph(n + 1);
  FOR(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    graph[--a].pb(--b);
    graph[b].pb(a);
  }
  color[0] = 1;
  q.push(0);
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    for(int next: graph[curr]) {
      if (color[next] == -1){
        color[next] = color[curr];
        q.push(next);
      }
    }
  }
  for(int i = 1; i < n; i++) {
    if (graph[i].size() == 1 && color[i] == 1) {
      return true;
    }
  }
  return false;
}

int main()
{
  fast_io;
  int t = 1;
  cin >> t;
  while (t--)
  {
    if (solve())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}