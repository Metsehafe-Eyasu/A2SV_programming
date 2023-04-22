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

int ans = 0;
void dfs(vector<vi> &graph, vi &cats, int index, int parent, int count, int limit, vector<bool>&visited)
{
    if (cats[index] == 1)
        count++;
    else
        count = 0;

    if (count > limit || visited[index])
        return;

    visited[index] = true;

    if (graph[index].size() == 1 && graph[index][0] == parent)
    {
        ans++;
        return;
    }
    for (auto &a : graph[index])
    {
        dfs(graph, cats, a, index, count, limit, visited);
    }
}

// Main function for solving the problem
void solve()
{
    // Start here
    int n, m;
    cin >> n >> m;
    vi cats(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }
    vector<vi> graph(n+1);
    FOR_(_, n - 1)
    {
        int from, to;
        cin >> from >> to;
        graph[from].pb(to);
        graph[to].pb(from);
    }

    vector<bool> visited(n+1, false);
    dfs(graph, cats, 1, 0, 0, m, visited);
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