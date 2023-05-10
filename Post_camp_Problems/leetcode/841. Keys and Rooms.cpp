#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            for (auto&a: rooms[room]) {
                if (visited[a]) continue;
                q.push(a);
                visited[a] = true;
            }
        }

        for(int i = 0; i < n; i++) 
            if (!visited[i]) return false;

        return true;
    }
};