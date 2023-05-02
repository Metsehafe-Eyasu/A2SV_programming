#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define FOR_(i, n) for (int i = 0; i < n; ++i)
#define FORR_(i, n) for (int i = n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

// Input list: customizable
template <typename T>
void inputList(vector<T> &arr, int n)
{
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

// Main function for solving the problem
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll>arr;
    inputList(arr, n);
    sort(arr.begin(), arr.end());
    ll dif  = 0;
    for(auto& a: arr) {
        if (a > x) break;
        dif += a;
    }    

    ll result = x*(x+1)/2 - (2*dif);
    cout << result << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}