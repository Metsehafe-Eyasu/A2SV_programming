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
int ans = 0;
void dfs(int i, int j, vi &a, vi &b, vector<vector<bool>> &visited, int count, int needed)
{
    int m = a.size(), n = b.size();
    if (i < 0 || i >= m || j < 0 || j >= n || a[i] * b[j] == 0 || visited[i][j])
        return;

    visited[i][j] = true;
    if (count >= needed) ans++;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        dfs(nx, ny, a, b, visited, count+1, needed);
    }
}

// int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
// {
//     int m = grid.size(), n = grid[0].size();
//     if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
//         return 0;

//     visited[i][j] = true;

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};
//     int count = 1;
//     for (int k = 0; k < 4; k++)
//     {
//         int nx = i + dx[k];
//         int ny = j + dy[k];
//         count += dfs(nx, ny, grid, visited);
//     }
//     return count;
// }

// Main function for solving the problem
void solve()
{
    // Start here
    int n, m, k;
    cin >> n >> m >> k;
    vi a, b;
    inputList(a, n);
    inputList(b, m);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    FOR_(i, n)
    {
        FOR_(j, m)
        {
            if (!visited[i][j] && a[i] * b[j] == 1)
            {
                dfs(i, j, a, b, visited, 1, k);
            }
        }
    }
    cout << ans << endl;
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