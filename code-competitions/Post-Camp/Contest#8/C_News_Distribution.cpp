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

class UnionFind {
    vector<int> parent;
    vector<int> sizes;
public: 
    UnionFind(int size) {
        parent.resize(size);
        sizes.resize(size);
        iota(parent.begin(), parent.end(), 0);
        fill(sizes.begin(), sizes.end(), 1);
    }
    int find(int x) {
        if (x != parent[x])
            x = find(parent[x]);
        return parent[x];
    }
    int findSize(int x) {
        x = find(x);
        return sizes[x];
    }
    void Union(int x, int y) {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep != y_rep) {
            int s1 = sizes[x_rep];
            int s2 = sizes[y_rep];
            if (s1 < s2) swap(x_rep, y_rep);
            
            sizes[x_rep] += sizes[y_rep];
            parent[y_rep] = parent[x_rep];
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// Main function for solving the problem
void solve()
{
    int n, r;
    cin >> n >> r;
    UnionFind un(n + 1);
    FOR_(_, r) {
        int k;
        cin >> k;
        vi ar;
        inputList(ar, k);
        FOR_(i, k - 1) {
            un.Union(ar[i], ar[i+1]);
        }
    }

    FOR_(i, n) {
        cout << un.findSize(i+1) << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}