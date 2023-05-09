#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define FOR_(i, n) for (int i = 0; i < n; ++i)
#define FORR_(i, n) for (int i = n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define sz(x) (int)x.size()
#define INF 1e9
#define MOD 1000000007

/**
 * @author ThePhenom-Pro: Metsehafe-Eyasu
 * @brief Custom template for CodeForces
 */

// Main function for solving the problem
void solve()
{
    int fromX, fromY, toX, toY;
    cin >> fromX >> fromY >> toX >> toY;
    unordered_map<int, unordered_map<int, int>> graph;
    int n;
    cin >> n;
    FOR_(_, n) {
        int row, cstart, cend;
        cin >> row >> cstart >> cend;
        for (int i = cstart; i <= cend; i++)
            graph[row][i] = 1;
    }
    int count = 0;
    queue<pii> q;
    q.push(mp(fromX, fromY));
    graph[fromX][fromY] = 0;

    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};  
    int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    
    bool check = false;
    while(!q.empty()) {
        int len = q.size();
        count++;
        FOR_(_, len) {
            pii path = q.front();
            q.pop();
            FOR_(k, 8) {
                int nx = path.first + dx[k];
                int ny = path.second + dy[k];
                if (nx == toX && ny == toY) {
                    cout << count << endl;
                    return;
                } 
                else if (graph[nx][ny]){
                    graph[nx][ny] = 0;
                    q.push(mp(nx, ny));
                }
            }
        }
    }
    cout << -1 << endl;

}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}