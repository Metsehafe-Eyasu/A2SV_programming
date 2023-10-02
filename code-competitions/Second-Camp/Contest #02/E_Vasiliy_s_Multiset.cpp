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


struct Node {
  int count;
  vector<Node*>children;
  Node () : count(0), children(2, NULL) {}
};

struct Trie {
  Node* root;
  Trie() : root(new Node()) {}
  void insert(int num) {
    Node* placer = root;
    int i = 31;
    while(i >= 0) {
      int val = (num >> i) & 1;
      if (!placer->children[val]) 
        placer->children[val] = new Node();
      placer->children[val]->count++;
      placer = placer->children[val];
      i--;
    }
  }
  void remove(int num) {
    Node* placer = root;
    int i = 31;
    while(i >= 0) {
      int val = (num >> i) & 1;
      placer->children[val]->count--;
      placer = placer->children[val];
      i--;
    }
  }
  int calc(int num) {
    int ans = 0;
    Node* finder = root;
    int i = 31;
    while(i >= 0) {
      int val = (num >> i) & 1;
      if (finder->children[(val^1)] && finder->children[(val^1)]->count > 0) {
        ans += (1 << i);
        finder = finder->children[(val^1)];
      }
      else if (finder->children[val] && finder->children[val]->count > 0)
        finder = finder->children[val];
      else break;
      i--;
    }
    return ans;
  }
};


// Main function for solving the problem
void solve() {
    // Start here
    Trie* trie = new Trie();
    trie->insert(0);
    int n;
    cin >> n;
    FOR(i, n) {
      char s;
      int val;
      cin >> s >> val;
      if (s == '+') trie->insert(val);
      else if (s == '-') trie->remove(val);
      else {
        cout << trie->calc(val) << endl;
      }
    }
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}