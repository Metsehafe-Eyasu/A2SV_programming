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

// Display list: Debugging purposes
template <typename T>
void display(vector<T> &arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

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
    // Start here
    int a, b;
    cin >> b >> a;
    vi arr;
    arr.pb(a);
    while (true) {
        if (a == b) {
            cout <<"YES" <<endl;
            break;
        } else if (a < b) {
            cout << "NO" << endl;
            return;
        } else if (a%2 == 0) {
            a/=2;
            arr.pb(a);
        } else if((a-1) % 10 == 0) {
            a = (a-1) / 10;
            arr.pb(a);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << arr.size() << endl;
    reverse(all(arr));
    display(arr);
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}