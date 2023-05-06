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

void dfs(int index, int &minVal, vector<vi> &graph, vi &costs, vector<bool> &visited)
{
    if (graph[index].empty())
    {
        minVal = costs[index];
        return;
    }
    minVal = min(minVal, costs[index]);
    visited[index] = true;
    for (auto &a : graph[index])
    {
        if (!visited[a])
            dfs(a, minVal, graph, costs, visited);
    }
}

// Main function for solving the problem
void solve()
{
    int n, p;
    cin >> n >> p;
    vi costs;
    inputList(costs, n);
    ll sum_ = 0;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    FOR_(_, p)  
    {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }

    FOR_(i, n)
    {
        if (!visited[i])
        {
            int minVal = 1000000000;
            dfs(i, minVal, graph, costs, visited);
            sum_ += minVal;
        }
    }
    cout << sum_ << endl;
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