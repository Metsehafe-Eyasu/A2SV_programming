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

bool dfs(vector<vector<int>>& graph, int color, int index, vector<int>& visited) {
    visited[index] = color;
    for (auto& child : graph[index]) {
        if (visited[child] == visited[index]) return false;
        if (visited[child] == 0 && !dfs(graph, 3 - visited[index], child, visited)) {
            return false;
        }
    }
    return true;
}
bool possibleBipart(int n, vector<vector<int>>& graph, vector<int>&visited) {
    for(int i = 1; i <= n; i++) {
        if (visited[i] == 0 && !dfs(graph, 1, i, visited)) return false;
    }
    return true;
}

// Main function for solving the problem
bool solve()
{
    int n;
    cin >> n;
    if (n == 0) return false;
    int k;
    cin >> k;
    vector<vector<int>>graph(n+1);
    vector<int> visited(n+1, 0);
    FOR_(i, k){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    if (!possibleBipart(n, graph, visited))
        cout << "NOT BICOLOURABLE." << endl;
    else 
        cout << "BICOLOURABLE." << endl;
    return true;
}

int main()
{
    fast;
    bool x = true;
    while (x) 
        x = solve();
    return 0;
}