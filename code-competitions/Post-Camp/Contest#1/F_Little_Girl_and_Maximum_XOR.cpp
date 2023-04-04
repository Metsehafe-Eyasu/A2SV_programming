#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
*/

void solution() {
    ll l, r;
    cin >> l >> r;

    ll ans = 0;
    for (ll i = 62; i >= 0; i--) {
        if ((l >> i) != (r >> i)) {
            ans = (1LL << (i + 1)) - 1;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    fast;
    solution();
}