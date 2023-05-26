#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topSort(vector<unordered_set<int>>& graph, vector<int>& indegree) {
        vector<int> ans;
        queue<int> q;
        for(int i =  0; i <indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            
            ans.push_back(t);
            
            for(int next : graph[t]) {
                --indegree[next];
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        for(int i =  0; i < indegree.size(); i++) {
            if(indegree[i] > 0) return {};
        }
        
        return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0; i < n; i++)
            if(group[i] == -1)
                group[i] = m++;
        
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> inGroup(m), inItem(n);
        for(int i = 0; i < n; i++) {
            int toGroup = group[i];
            for(int from : beforeItems[i]) {
                int fromGroup = group[from];
                if(fromGroup != toGroup && !graphGroup[fromGroup].count(toGroup)) {
                    graphGroup[fromGroup].insert(toGroup);
                    inGroup[toGroup]++;
                }
                if(!graphItem[from].count(i)) {
                    graphItem[from].insert(i);
                    inItem[i]++;
                }
            }
        }
        vector<int> sortedGroup = topSort(graphGroup, inGroup);
        vector<int> sortedItems = topSort(graphItem, inItem);
        
        if(sortedGroup.empty() || sortedItems.empty()) return {};

        vector<vector<int>> group2item(m);
        for(auto item : sortedItems){
            group2item[group[item]].push_back(item);
        }
        
        vector<int> ans;
        for(int group_id : sortedGroup) {
            for(int item : group2item[group_id]) {
                ans.push_back(item);
            }
        }
        
        return ans;
    }
};