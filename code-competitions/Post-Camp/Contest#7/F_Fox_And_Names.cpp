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
bool top_sort(vector<vi>& graph, string& result) {
    vi inDegree(26, 0);
    FOR_(i, 26)
        for(int curr: graph[i]) 
            inDegree[curr]++;
    queue<int>q;
    FOR_(i, 26) 
        if (inDegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        result.pb(curr + 'a');
        for(int num: graph[curr])
            if (--inDegree[num] == 0) 
                q.push(num);
    }
    return result.length() == 26;
}

// Main function for solving the problem
void solve()
{
    int n;
    cin >> n;
    vector<string>names;
    inputList(names, n);
    vector<vi>graph(26);
    bool valid = true;
    for(int i = 1; i < n && valid;i++) {
        const string& a = names[i-1], b = names[i];
        int j = 0;
        for(j; j<a.length() && j < b.length() && a[j]== b[j]; j++) {}
        if (j < a.length() && j < b.length()) 
            graph[a[j] - 'a'].pb(b[j] - 'a');
        else if (a.length() > b.length())
            valid = false;
    }
    if (valid) {
        string result;
        if (top_sort(graph, result)) cout << result << endl;
        else cout << "Impossible\n";
    } else {
        cout << "Impossible\n";
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