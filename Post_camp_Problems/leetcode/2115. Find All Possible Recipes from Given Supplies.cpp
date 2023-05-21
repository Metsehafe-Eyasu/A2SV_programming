#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> hash;
        unordered_map<string, int> indegree;
        unordered_map<string, int> sup;
        for(auto&a: supplies) {
            sup[a]++;
        }
        set<string>rec(recipes.begin(), recipes.end());
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            for(auto& a: ingredients[i]) {
                hash[a].push_back(recipes[i]);
                indegree[a] += 0;
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto [key, val]: indegree) {
            if(val == 0 && sup[key] > 0){
                sup[key]--;
                q.push(key);
            } 
        }
        vector<string>ans;
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if (rec.count(curr)) {
                sup[curr]++;
                ans.push_back(curr);
            }
            for(auto& a: hash[curr]) {
                indegree[a]--;

                if (indegree[a] == 0){
                    sup[a]--;
                    q.push(a);
                } 
            }
        }
        return ans;
    }
};