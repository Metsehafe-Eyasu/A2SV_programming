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

ll squareRoot(ll x) {
    if (x == 0 || x == 1) return x;
    ll left = 1, right = x;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (mid * mid > x) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

vvl pyramid(1500, vl(1500, -1));

void fill() {
    ll x = 1;
    FOR(i, 1500) {
        FOR(j, i+1) {
            pyramid[i][j] = x*x;
            x++;
        }
    }
    FOR(i, 1500-2) {
        FOR(j, i+1) {
            pyramid[i+1][j] += pyramid[i][j];
            pyramid[i+1][j+1] += pyramid[i][j];
            pyramid[i+2][j+1] -= pyramid[i][j];
        }
    }
}



// Main function for solving the problem
void solve() {
    // Start here
    ll n;
    cin >> n;
    --n;
    ll i = (-1 + squareRoot(1 + 8*n))>>1;
    ll j = n - i*(i+1)/2;
    cout << pyramid[i][j] << endl;
}

int main() {
    fast_io;
    fill();
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}