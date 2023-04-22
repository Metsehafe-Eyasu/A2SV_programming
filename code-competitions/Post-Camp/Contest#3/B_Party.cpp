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

// Input list: customizable
template <typename T>
void inputList(vector<T> &arr, int n)
{
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

int dfs(vi& graph, int index, int depth) {
    if (graph[index] == -1) return depth;
    return dfs(graph, graph[index], depth+1);
}

// Main function for solving the problem
void solve()
{
    // Start here
    int n;
    cin >> n;
    vi v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int maxDepth = 0;
    for(int i = 1; i <= n; i++){
        maxDepth = max(maxDepth, dfs(v, i, 1));
    }
    
    cout << maxDepth << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}