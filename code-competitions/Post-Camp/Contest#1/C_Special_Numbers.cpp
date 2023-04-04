#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
*/

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solution() {
    ll a, b;
    cin >> a >> b;
    
    ll c = 0;
    ll count = 0;

    ll d = 1;
    while (b > 0) {
        if (d&b) c = (c + power(a, count)) % MOD;
        count++;
        b >>= 1;
    }
    c = c % MOD;
    cout << c << endl;
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solution();
    }
}