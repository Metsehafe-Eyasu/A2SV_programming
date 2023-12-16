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
typedef priority_queue<int, vector<int>, greater<int>> min_pq;
typedef priority_queue<int> max_pq;

// Macros
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);
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
void IL(vector<T> &arr, int n)
{
  arr.resize(n);
  for (auto &a : arr)
    cin >> a;
}

string check = "abacaba";
// Main function for solving the problem
void solve()
{
  // Start here
  int n;
  string s;
  cin >> n >> s;
  FOR(i, n - 6)
  {
    string s_copy = s;
    bool flag = true;
    FOR(j, 7)
    {
      if (s_copy[i + j] == '?')
      {
        s_copy[i + j] = check[j];
      }
      else if (s_copy[i + j] != check[j])
      {
        flag = false;
        break;
      }
    }
    if (!flag)
      continue;
    FOR(i, n)
    {
      if (s_copy[i] == '?')
        s_copy[i] = 'z';
    }
    size_t idx = s_copy.find(check);
    if (idx == string::npos)
      continue;
    size_t second_idx = s_copy.find(check, idx + 1);
    if (second_idx == string::npos)
    {
      cout << "Yes" << endl
           << s_copy << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main()
{
  fast_io;
  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}