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

bool bipartite;

void dfs(int index, int c, vector<vi>& graph, vector<int>& colored) {
    colored[index] = c;
    for(auto&a: graph[index]) {
        if (colored[a] == -1) dfs(a, 1 - c, graph, colored);
        else if (colored[a] == c) bipartite = false;
    }
}

// Main function for solving the problem
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);
    vpii pairs;
    FOR_(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].pb(y);
        graph[y].pb(x);
        pairs.pb({x, y});
    }
    bipartite = true;
    vector<int> colored(n, -1);
    dfs(0, 0, graph, colored);
    if (!bipartite) cout << "NO \n";
    else {
        cout << "YES\n";
        FOR_(i, m) {
            cout << (colored[pairs[i].first] < colored[pairs[i].second]);
        } 
    }
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}