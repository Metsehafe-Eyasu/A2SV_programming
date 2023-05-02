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

void lowerCase(string& a) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}

int dfs(unordered_map<string, vector<string>>&graph, string s) {
    if (graph[s].empty()) return 1;
    int len = 0;
    for(auto&a : graph[s]){
        len = max(len, dfs(graph, a));
    }
    return len + 1;
}

// Main function for solving the problem
void solve()
{
    int n;
    cin >> n;
    unordered_map<string, vector<string>>graph;
    FOR_(i, n){
        string a, _ ,b;
        cin >> a >> _ >> b;
        lowerCase(a);
        lowerCase(b);
        graph[b].push_back(a);
    }
    cout << dfs(graph, "polycarp") <<endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}