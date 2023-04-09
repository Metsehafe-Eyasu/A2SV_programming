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


// display list: Debugging purposes
void display(vector<int>& arr) {
    for (auto& i: arr)
        cout << i << " ";
    cout << endl;
}

// Input list: customizable
void inputList(vector<int>& arr, int n) {
    for (auto& a: arr) {
        cin >> a;
    }
}

void solution() {
    int rows, cols;
    cin >> rows >> cols;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (((r1 == 1 || r1 == rows) && (c1 == 1 || c1 == cols)) || ((r2 == 1 || r2 == rows) && (c2 == 1 || c2 == cols)))
        cout << 2 << endl;
    else if (((r1 == 1 || r1 == rows) || (c1 == 1 || c1 == cols)) || ((r2 == 1 || r2 == rows) || (c2 == 1 || c2 == cols)))
        cout << 3 << endl;
    else
        cout << 4 << endl;
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solution();
    }
}