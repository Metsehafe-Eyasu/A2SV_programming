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
typedef tuple<int, int, int, int> t4i;

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
void display(vector<T> &arr)
{
  for (auto &i : arr)
    cout << i << " ";
  cout << endl;
}

template <typename T>
void inputList(vector<T> &arr, int n)
{
  arr.resize(n);
  for (auto &a : arr)
    cin >> a;
}

bool inBound(int i, int j, int n, int m)
{
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

// Main function for solving the problem
void solve()
{
  // Start here
  int n, m;
  cin >> n >> m;
  int i, j;
  cin >> i >> j;
  int maxLeft, maxRight;
  cin >> maxLeft >> maxRight;
  vs grid(n);
  inputList(grid, n);
  queue<t4i> q;
  q.emplace(i - 1, j - 1, maxLeft, maxRight);
  int count = 1;
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<vector<pii>> visited(n, vector<pii>(m, {-1, -1}));
  visited[i-1][j-1] = mp(maxLeft, maxRight);
  while (!q.empty())
  {
    auto [x, y, ml, mr] = q.front();
    q.pop();
    for (auto &dir : dirs)
    {
      int nx = x + dir[0], ny = y + dir[1];
      if (!inBound(nx, ny, n, m) || grid[nx][ny] == '*')
        continue;
      int nml = ml, nmr = mr;
      if (dir[1] == 1)
        nmr--;
      if (dir[1] == -1)
        nml--;

      if (nml >= 0 && nmr >= 0)
      {
        if (visited[nx][ny] == mp(-1, -1))
          count++;
        if (visited[nx][ny] < mp(nml, nmr)){
          q.emplace(nx, ny, nml, nmr);
          visited[nx][ny] = {nml, nmr};
        }
      }
    }
  }
  cout << count << "\n";
}

int main()
{
  fast_io;
  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}