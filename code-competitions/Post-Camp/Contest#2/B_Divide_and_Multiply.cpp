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
void display(vector<ll>& arr) {
    for (auto& i: arr)
        cout << i << " ";
    cout << endl;
}
 
// Input list: customizable
void inputList(vector<ll>& arr, int n) {
    for (auto& a: arr) {
        cin >> a;
    }
}

ll extract(vector<ll>& arr, int index) {
    ll count = 1;
    while ((arr[index]&1) == 0){
        count <<=1;
        arr[index] >>=1;
    }
    return count;
}
 
void solution() {
    int n;
    cin >> n;
    vector<ll>arr(n);
    inputList(arr, n);
    ll evens = 1;
    int m = 0, ind = -1;
    for(int i = 0; i < n; i++) {
        if (arr[i]%2 == 0){
            evens *= extract(arr, i); 
        } 
        if (arr[i] > m) {
            ind = i;
            m = arr[i];
        }
    }
    arr[ind] *= evens;
    ll all = 0;
    for(int i = 0; i < n; i++) {
        all += arr[i];
    }
    cout << all <<  endl;
    
    
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solution();
    }
}