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

void sieve(vector<int> &eratos, int right)
{
    for (int i = 2; i*i < right; i++)
    {
        if (eratos[i] == 1)
            for (int j = i * i; j < right; j += i)
                eratos[j] = 2;
    }
    if (right > 4)
        cout << 2 << endl;
    else
        cout << 1 << endl;

    for (int i = 2; i < right; i++)
    {
            cout << eratos[i] << " ";
    }
    cout << endl;
}

void solution()
{
    int n;
    cin >> n;
    vector<int> arr(n + 2, 1);
    sieve(arr, n + 2);
}

int main()
{
    fast;
    solution();
}