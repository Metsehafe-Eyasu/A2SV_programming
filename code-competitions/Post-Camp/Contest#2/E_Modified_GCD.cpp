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

// Binary search
template <typename T>
int binarySearch(vector<T> &arr, T target)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return (arr[left] == target) ? left : -1;
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

void solve(){
    int a, b;
    cin >> a >> b;

    int x = __gcd(a, b);
    set<int, greater<int>>  factors;

    for(int i = 1; i*i <= x; i++) {
        if (x%i == 0){
            factors.insert(i);
            factors.insert(x/i);
        }
    }

    int cases;
    cin >> cases;

    while (cases--) {
        int r, l;
        cin >> l >> r;

        int res = *lower_bound(factors.begin(), factors.end(), r, greater<int>());
        if (res > r || res < l) cout << -1 << endl;
        else cout << res << endl;
    }
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}