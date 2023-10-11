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

vector<int> builder(string s) {
    int n = s.size(), j = 0, i = 1;
    vector<int> arr(n, 0);
    while(i < n) {
        if (s[i] == s[j]) arr[i++] = ++j;
        else if (j > 0) j = arr[j-1];
        else i++;
    }
    return arr;
}

// Main function for solving the problem
void solve() {
    string s;
    cin >> s;
    vector<int> pi = builder(s);
    int n = s.size();
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++){
      arr[pi[i]]++;
    }
    for (int i = n-1; i > 0; i--){
      arr[pi[i-1]]+=arr[i];
    }
    for (int i =0; i <=n;i++){
      arr[i]++;
    }
    vector<int> ans(n+1,0);
    int i = n;
    ans[n]=1;
    int k = 0;
    while(i>0){
      i = pi[i-1];
      ans[i] = arr[i];
      if(ans[i] != 0) k++;
    }
    // display(pi);
    // display(arr);
    // display(ans);
    cout<<k<<endl;
    for (int len = 1; len <= n;len++){
      if(ans[len] != 0){
        cout<<len<<" "<<ans[len]<<endl;
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