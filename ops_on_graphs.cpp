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
    int nodes;
    cin >> nodes;
    vector<vector<int>> graph(nodes + 1);
    int ops;
    cin >> ops;
    forn(i, ops){
        int opType;
        cin >> opType;

        if (opType == 1) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        } else {
            int wanted;
            cin >> wanted;

            cout << (graph[wanted].size() + 1) << endl;
        }
    }
}

int main() {
    fast;
    solution();
}