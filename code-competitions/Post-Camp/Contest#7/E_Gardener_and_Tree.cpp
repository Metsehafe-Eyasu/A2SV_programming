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

// Main function for solving the problem
void solve()
{
    int n, r;
    cin >> n >> r;
    vector<vi>graph(n);
    vi inDegree(n, 0);
    vi layer(n, 0);
    FOR_(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].pb(b);
        graph[b].pb(a);
        inDegree[a]++;
        inDegree[b]++;
    }

    queue<int>q;
    FOR_(i, n) {
        if (inDegree[i] == 1){
            q.push(i);
            layer[i] = 1;
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto&child: graph[curr]) {
            if(inDegree[child] != 1 & --inDegree[child] == 1) {
                layer[child] = layer[curr] + 1;
                q.push(child);
            }
        } 
    }

    int ans = 0;
    FOR_(i, n) {
        if (layer[i] > r) ans++; 
    }
    cout << ans << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}