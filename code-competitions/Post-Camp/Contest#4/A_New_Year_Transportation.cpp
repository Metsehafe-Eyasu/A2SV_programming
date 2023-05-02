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


bool dfs(vector<int>& arr, int index, int target) {
    if (target == index) return true;
    if (index >= target) return false;

    return dfs(arr, arr[index], target);
}

// Main function for solving the problem
void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int>graph(n);
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        graph[i] = i+x;
    }
    if (dfs(graph, 1, target))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}