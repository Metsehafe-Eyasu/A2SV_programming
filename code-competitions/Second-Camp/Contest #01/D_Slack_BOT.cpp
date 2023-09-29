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


class Node
{
public:
  int val;
  vector<Node*>children;
  Node() : children(26, NULL), val(0) {}
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* placer = root;
        int n = word.length();
        FOR(i, n) {
            int index = word[i] - 'a';
            if (!placer->children[index])
                placer->children[index] = new Node();
            placer->children[index]->val++;
            placer = placer->children[index];
        }
    }

    int startsWith(string prefix) {
        Node* runner = root;
        int ans = 0;
        int n = prefix.length();
        FOR(i, n) {
            int index = prefix[i] - 'a';
            if (runner->children[index] == NULL || runner->children[index]->val < 2)
                break;
            ans++;
            runner = runner->children[index];
        }
        return ans;
    }
};

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
    int n;
    cin >> n;
    vector<string>arr(n);
    Trie* trie = new Trie();
    FOR(i, n) {
        string s;
        cin >> s;
        trie->insert(s);
        arr[i] = s;
    }
    for(string &s: arr) {
        cout << trie->startsWith(s) << "\n";
    }
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}