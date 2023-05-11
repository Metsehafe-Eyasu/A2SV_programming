#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int racecar(int target) {
        queue<array<long long, 3>> q;
        set<pair<long long, long long>> visited;
        q.push({1, 0, 0});
        visited.insert({1, 0});
        while(!q.empty()) {
            auto [speed, path, position] = q.front();
            q.pop();
            cout << speed << " " << path << " " << position << endl;
            if (position == target) 
                return path;

            if (!visited.count({speed*2, position + speed})) {
                visited.insert({speed*2, position + speed});
                q.push({speed*2, path+1, position + speed});
            }
            if (!visited.count({((speed > 0) ? -1 : 1), position})) {
                if ((position + speed > target && speed > 0) || (position + speed < target && speed <= 0))
                speed = (speed > 0) ? -1 : 1;
                visited.insert({speed, position});
                q.push({speed, path+1, position});
            }

        }
        return -1;
    }
};