#include <bits/stdc++.h>
using namespace std;

// Shorthand notations
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef set<int> si;
typedef set<ll> sl;
typedef priority_queue<int, vector<int>, greater<int>> min_pq;
typedef priority_queue<int> max_pq;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORR(i, n) for (int i = n - 1; i >= 0; --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define forRange(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

// Modular exponentiation function
ll mod_exp(ll x, ll y, ll m) {
    x%=m;
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

ll squareRoot(ll x) {
    if (x == 0 || x == 1) return x;
    ll left = 1, right = x;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (mid * mid > x) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

// String to int vector
vi STIV(const string &str)
{
    vi v;
    for (char c : str)
        if (isdigit(c))
            v.push_back(stoi(string(1, c)));
    return v;
}

// Display list (for debugging purposes)
template <typename T>
void display(vector<T> &arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Input list (customizable)
template <typename T>
void inputList(vector<T> &arr, int n)
{
    arr.resize(n);
    for (auto &a : arr)
        cin >> a;
}

// Sort function
void sort_(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// Search function
void search(vector<int>& arr, int x) {
    int index = find(arr.begin(), arr.end(), x) - arr.begin();
    if (index < 0) index = -1;
    cout << index << endl;
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool is_prime(ll n)
{
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

template <typename T>
int binary_search(const vector<T> &v, T target)
{
    int left = 0, right = sz(v) - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

struct UnionFind
{
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};


// Pair hash
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

vector<ll> dijkstra(int source, vector<vector<pair<int, ll>>> &adj)
{
    int n = adj.size();
    vector<ll> dist(n, INF);
    dist[source] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (auto &edge : adj[v])
        {
            int u = edge.first;
            ll w = edge.second;

            if (dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }

    return dist;
}

vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) 
        if (isPrime[i]) 
            for (int j = i * i; j <= n; j += i) 
                isPrime[j] = false;

    return isPrime;
}


// Main function for solving the problem
void solve()
{
    
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
