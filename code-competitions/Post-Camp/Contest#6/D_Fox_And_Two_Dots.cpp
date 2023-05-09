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

bool dfs(int i, int j, vector<string>& grid, pii p, vector<vector<bool>>& visited, char color) {
    int n = grid.size(), m = grid[0].size();
    visited[i][j] = true;
    int dx[4] = {0, 1, 0, -1};  
    int dy[4] = {1, 0, -1, 0};
    bool check = false;
    FOR_(k, 4) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m
        || (grid[nx][ny] != color)) 
            continue;
        else if (visited[nx][ny] && (nx != p.first || ny != p.second) ) return true;
        else if (!visited[nx][ny])
            check = dfs(nx, ny, grid, mp(i, j), visited, color) ? true : check;
    }
    return check;
}

// Main function for solving the problem
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    cin.ignore();
    FOR_(i, n) {
        cin >> grid[i];
    }
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    FOR_(i, n) {
        FOR_(j, m) {
            if (!visited[i][j] && dfs(i, j, grid, mp(-1, -1), visited, grid[i][j])) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}