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
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void solution() {
    int total;
    cin >> total;
    
    vector<int>graph(total+1);
    inputList(graph, total);
    for(int i = 1; i <= total; i++) {
        if (graph[graph[graph[i]]] == i) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    fast;
    solution();
}