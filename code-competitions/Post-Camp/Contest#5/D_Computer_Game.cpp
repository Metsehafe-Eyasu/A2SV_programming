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

bool dfs(vector<vector<bool>> &grid, int i, int j)
{
    int m = 2, n = grid[0].size();
    if (i == m-1 && j == n - 1) return true;
    if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
        return false;
    grid[i][j] = false;
    int dx[3] = {0, 1, -1};
    int dy[3] = {1, 1, 1};
    FOR_(k, 3)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (dfs(grid, nx, ny))
            return true;
    }
    return false;
}

// Main function for solving the problem
void solve()
{
    int n;
    cin >> n;
    vector<vector<bool>> grid(2, vector<bool>(n));
    FOR_(i, 2)
    {
        string s;
        cin >> s;
        FOR_(j, n)
        grid[i][j] = s[j] == '0' ? true : false;
    }

    cout << (dfs(grid, int(0), int(0)) ? "YES" : "NO") << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}