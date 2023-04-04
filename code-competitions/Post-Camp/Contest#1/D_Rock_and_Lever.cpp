#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
*/

// Input list: customizable
void inputList(vector<int>& arr, int n) {
    for (auto& a: arr) {
        cin >> a;
    }
}

void solution() {
    ll n;
    cin >> n;
    vector<int> a(n);
    inputList(a, n);

    ll ans = 0;
    for (int j=29; j>=0; j--){
        ll cnt=0;
        for (int i=0; i<n; i++){
            if (a[i] >= (1<<j) && a[i] < (1<<(j+1)) ){
                cnt++;
            }
        }
        ans+=cnt*(cnt-1)/2;
    }
    cout<<ans<<'\n';
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solution();
    }
}