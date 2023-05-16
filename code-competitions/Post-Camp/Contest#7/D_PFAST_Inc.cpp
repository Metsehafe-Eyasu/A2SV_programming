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

// Main function for solving the problem
void solve()
{
    int n, m;
    cin >> n >> m;
    map<string, int>nameIdx;
    vector<string>names(n);
    FOR_(i, n) 
        cin >> names[i];
    sort(names.begin(), names.end());
    FOR_(i, n) 
        nameIdx[names[i]] = i;

    vector<vector<bool>> graph(n, vector<bool>(n, true));
    FOR_(i, m) {
        string a, b;
        cin >> a >> b;
        graph[nameIdx[a]][nameIdx[b]] = false;
        graph[nameIdx[b]][nameIdx[a]] = false;
    }
    
    int maxSize = 0;
    vector<int>maxTeam;
    FOR_(mask, 1 << n) {
        bool valid = true;
        vi currTeam;
        for(int i = 0; i < n && valid; i++) {
            if (mask & (1 << i)) {
                for(int j: currTeam) {
                    if (!graph[i][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) currTeam.pb(i);
            }
        }
        if (valid && currTeam.size() > maxSize){
            maxSize = currTeam.size();
            maxTeam = currTeam;
        }
    }

    cout << maxSize << endl;
    for(int i: maxTeam) cout << names[i] << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}