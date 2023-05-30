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

// int n = arr.size() - 1 - (find(arr.rbegin(), arr.rend(), 1) - arr.rbegin());

template <typename T>
void display(vector<T> &arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> STIV(const string &str)
{
    vector<int> v;
    for (char c : str)
        if (isdigit(c))
            v.push_back(stoi(string(1, c)));
    return v;
}

// Main function for solving the problem
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vi zero(3, -1);
    for(int i = s.size() - 1; i >=0; i--) {
        if (zero[1] == -1 && zero[0] != -1 && s[i] == '0') {
            zero[1] = i;
        } else if ( zero[2] == -1 && zero[0] != -1 && s[i] == '5') {
            zero[2] = i;
        } else if (zero[0] == -1 && s[i] == '0')
            zero[0] = i;
    }
    vi five(3, -1);
    for(int i = s.size() - 1; i >=0; i--) {
        if (five[1] == -1 && five[0] != -1 && s[i] == '2') {
            five[1] = i;
        } else if (five[2] == -1 && five[0] != -1 && s[i] == '7') {
            five[2] = i;
        } else if (five[0] == -1 && s[i] == '5')
            five[0] = i;
    }
    int ans = INT_MAX;
    if (zero[0] != -1) {
        if (zero[1] != -1)
            ans = min(ans, n - (zero[1] + 2));
        if (zero[2] != -1)
            ans = min(ans, n - (zero[2] + 2));
    }
    if (five[0] != -1) {
        if (five[1] != -1)
            ans = min(ans, n - (five[1] + 2));
        if (five[2] != -1)
            ans = min(ans, n - (five[2] + 2));
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