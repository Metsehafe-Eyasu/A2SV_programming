#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < tasks.size(); i++)
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int>answer;
        long long currTime = 0;
        int index = 0;
        while (index < tasks.size() || !pq.empty()) {
            if (pq.empty() && currTime < sortedTasks[index][0]) 
                currTime = sortedTasks[index][0];

            while(index < sortedTasks.size() && currTime >= sortedTasks[index][0]){
                pq.push({sortedTasks[index][1], sortedTasks[index][2]});
                index++;
            }
            auto [processTime, i] = pq.top();
            pq.pop();
            currTime += processTime;
            answer.push_back(i);
        }        
        return answer;
    }
};