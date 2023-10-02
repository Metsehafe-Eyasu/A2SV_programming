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
    int n, s;
    cin >> n >> s;
    if (n > 1 && s == 0) {
        cout << "-1 -1\n";
        return;
    }
    vi min_num(n, 0), max_num(n, 0);
    int s2 = s;
    min_num[0] = 1;
    s--;
    int placer = n-1; 
    while(placer > 0) {
        if (s < 9) break;
        min_num[placer] += 9;
        s -= 9;
        placer--;
    }
    if (placer == 0 && s > 8) {
        cout << "-1 -1\n";
        return;
    }
    min_num[placer] += s;
    string ans_min = "";
    for(int i: min_num) ans_min += to_string(i);

    placer = 0;
    while(placer < n) {
        if (s2 > 9) {
            max_num[placer] = 9;
            s2 -= 9;
        }
        else {
            max_num[placer] = s2;
            s2 = 0;
        }
        placer++;
    }
    
    string ans_max = "";
    for(int i: max_num) ans_max += to_string(i);
    cout << ans_min << " " << ans_max<< endl;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}