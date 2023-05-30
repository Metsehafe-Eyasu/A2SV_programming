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

struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

// Main function for solving the problem
void solve()
{
    int n;
    cin >> n;
    UnionFind uf(n+1);
    queue<pii>q;
    FOR_(i, n-1) {
        int a, b;
        cin >> a >> b;
        if (uf.isConnected(1, a) || uf.isConnected(1, b)) {
            uf.unite(a, b);
        } else {
            q.push({a, b});
        }
    }
    int ans = 1;
    while (!q.empty())
    {
        ans++;
        int len = q.size();
        FOR_(_, len) {
            auto top = q.front();
            q.pop();
            if (uf.isConnected(1, top.first) || uf.isConnected(1, top.second)) {
                uf.unite(top.first, top.second);
            } else {
                q.push(top);
            }
        }
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