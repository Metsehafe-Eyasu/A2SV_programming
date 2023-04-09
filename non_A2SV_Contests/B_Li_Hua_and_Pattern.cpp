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

// display list: Debugging purposes
void display(vector<int> &arr)
{
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;
}

// Input list: customizable
void inputList(vector<int> &arr)
{
    for (auto &a : arr)
    {
        cin >> a;
    }
}

void solution()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &a : grid)
    {
        inputList(a);
    }
    int sideA = n / 2, sideB = sideA + (int)(n % 2 != 0);
    int count = 0;
    for (int i = 0; i < sideA; i++)
    {
        for (int j = 0; j < sideB; j++)
        {
            // cout << i << " " << j << endl;
            if (grid[i][j] != grid[n - 1 - i][n - 1 - j])
                count++;
        }
    }
    // cout << "----------------" << endl;
    for (int i = sideA; i < n; i++)
    {
        for (int j = 0; j < sideA; j++)
        {
            // cout << i << " " << j << endl;
            if (grid[i][j] != grid[n - 1 - i][n - 1 - j])
                count++;
        }
    }
    // cout << "count: " << count << endl;
    if (count <= k && (count % 2 == k % 2))
        cout << "YES" << endl;
    else if(count <= k && n%2 != 0 && (count % 2 != k % 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    fast;
    int i;
    cin >> i;
    forn(_, i)
    {
        solution();
    }
}