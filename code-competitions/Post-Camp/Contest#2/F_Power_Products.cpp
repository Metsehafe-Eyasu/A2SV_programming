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

map<ll, ll> factorize(ll n, ll k)
{
    map<ll, ll> x;
    ll co = n;
    for (long long i = 2; i * i <= co; i++) {
        while (co % i == 0) {
            x[i]++;
            x[i] = x[i] % k;
            co = co / i;
        }
    }
    if (co > 1) x[co]++;

    map<ll, ll> res;
    for (map<ll, ll>::iterator y = x.begin(); y != x.end(); ++y)
        if (!(y->second == 0 || y->second == k))
            res[y->first] = y->second % k;
    
    return res;
}

// Main function for solving the problem
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>arr;
    inputList(arr, n);

    map<map<ll, ll>, ll> store;
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << arr[i] << endl;
        map<ll, ll> curr = factorize(arr[i], k);
        map<ll, ll> inv;
        for (map<ll, ll>::iterator x = curr.begin(); x != curr.end(); ++x)
            inv[x->first] = k - x->second;
            
        count += store[inv];
        store[curr]++;
    }
    cout << count << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}