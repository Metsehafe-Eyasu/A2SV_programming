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

class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size);
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

typedef tuple<ll,int,int> T;

// Main function for solving the problem
void solve()
{
    int n, d;
    cin >> n >> d;
    vl arr(n);
    FOR_(i, n) {
        cin >> arr[i];
    }
    
    vector<T> v;
    FOR_(i, d) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--; y--;
        v.pb({w, x, y});
    }

    int bestIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[bestIdx]) {
            bestIdx = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != bestIdx) {
            v.pb({arr[i] + arr[bestIdx], i, bestIdx});
        }
    }

    sort(all(v));
    UnionFind un(n);
    ll ans = 0;
    for (const auto& [w, x, y] : v) {
        if (un.Union(x, y)) {
            ans += w;
        }
    }

    cout << ans << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}