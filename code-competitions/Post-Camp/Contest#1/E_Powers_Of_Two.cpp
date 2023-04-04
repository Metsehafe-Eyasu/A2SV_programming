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

int counter(int a, vector<int>&arr) {
    int x = 1;
    int count = 0;
    while (x <= a) {
        if (a&x) {
            arr.push_back(x);
        }
        x <<= 1;
    }
    return arr.size();
}

void solution() {
    int a, b;
    cin >> a >> b;
    vector<int>arr;
    int count = counter(a, arr);
    if (b > a || count > b) {
        cout << "NO" << endl;
        return;
    }
    int k = 0;
    while (!arr.empty() && arr.size() + k < b) {
        int num = arr.back();
        if (num == 1) {
            k++;
            arr.pop_back();
        } else {
            arr.back() >>= 1;
            arr.push_back(arr.back());
        }
    }
    cout << "YES" << endl;
    while (k--) {
        cout << "1 ";
    }
    display(arr);
}

int main() {
    fast;
    solution();
}