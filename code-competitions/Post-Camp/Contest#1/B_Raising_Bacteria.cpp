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
    int x;
    cin >> x;
    int a = 1, count = 0;
    while (a <= x) {
        if (a&x) count++;
        a <<= 1;
    }
    cout << count << endl;
}

int main() {
    fast;
    solution();
}