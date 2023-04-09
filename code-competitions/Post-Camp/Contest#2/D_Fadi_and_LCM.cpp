#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

void solution()
{
    ll n;
    cin >> n;
    ll ans;
    for (ll i = 1 ; i * i <= n ; i++)
    {
        if(n % i == 0 && lcm(i, n / i) == n)
            ans = i;
    }

    cout << ans << " " << n / ans << endl;
}

int main()
{
    fast;
    solution();
}