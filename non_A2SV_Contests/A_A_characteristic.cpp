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

// Function for modular exponentiation
ll mod_exp(ll x, ll y, ll m)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

// String to int vector
vector<int> STIV(const string &str)
{
    vector<int> v;
    for (char c : str)
        if (isdigit(c))
            v.push_back(stoi(string(1, c)));
    return v;
}

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
void filler(vector<int>& arr, int bp) {
    for(int i = 0; i < bp; i++)
        arr[i] = 1;
    for(bp; bp < arr.size(); bp++)
        arr[bp] = -1;
}

// Main function for solving the problem
void solve()
{
    ll n, k;
    cin >> n >> k;
    string ans = "NO";
    vector<int>arr(n);
    if (n == 2 && k == 0) {
        ans = "YES";
        filler(arr, 1);
    } else if (k == n*(n-1)/2) {
        ans = "YES";
        filler(arr, n);
    } else {
        for(int i = 1; i <= n/2; i++) {
            ll a = (n - i)*(n - i - 1)/2;
            ll b = i*(i-1)/2;
            if (a+b == k) {
                ans = "YES";
                filler(arr, i);
                break;
            }
        }
    }

    cout << ans << endl;
    if (ans == "YES") {
        display(arr);
    }
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}