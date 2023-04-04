#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)

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
void inputList(vector<int>& arr) {
    for (auto& a: arr) {
        cin >> a;
    }
}

void solution() {
    int a;
    cin >> a;
    vector<int>arr(a);
    inputList(arr);
    cout << arr[0] << endl;
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solution();
    }
}