#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string goal = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string curr = "";
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[0].size(); j++) 
                curr += to_string(board[i][j]);
        queue<pair<string, int>>q;
        q.push({curr, 0});
        unordered_map<string, bool> visited;
        visited[curr] = true; 
        while(!q.empty()) {
            auto [comb, move] = q.front();
            q.pop();
            if (comb == goal) return move;
            int index = comb.find('0');
            for(auto&a: moves[index]) {
                string next = comb;
                swap(next[index], next[a]);
                if (!visited[next]) {
                    q.push({next, move+1});
                    visited[next] = true;
                }
            }
        }
        return -1;
    }
};