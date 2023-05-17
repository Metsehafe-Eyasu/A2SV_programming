#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> cells(n*n + 1);
        vector<int>distance(n*n+1, -1);
        vector<int>cols(n);
        queue<int>q;

        int label = 1;
        iota(cols.begin(), cols.end(), 0);
        for(int r = n-1; r >= 0; r--) {
            for(auto col: cols)
                cells[label++] = {r, col};
            reverse(cols.begin(), cols.end());
        }

        distance[1] = 0;
        q.push(1);
        while(!q.empty()) {
            int from = q.front();
            q.pop();
            for(int i = from+1; i <= min(from+6, n*n); i++) {
                auto [row, col] = cells[i];
                int to = board[row][col] != -1 ? board[row][col] : i;  
                if (distance[to] == -1) {
                    distance[to] = distance[from] + 1;
                    q.push(to);
                }
            }
        }
        return distance[n*n];
    }
};