#include <bits/stdc++.h>
using namespace std;
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int count = 0;
    void dfs(vector<Employee*> emp, int id, vector<bool>& visited) {
        if (visited[id]) return;
        count += emp[id]->importance;

        for(auto& a: emp[id]->subordinates)
            dfs(emp, a, visited);
    }
    int getImportance(vector<Employee*> employees, int id) {
        vector<Employee*> emp(2001);
        vector<bool> visited(2001, false);

        for(int i = 0; i < employees.size(); i++) {
            emp[employees[i]->id] = employees[i]; 
        }
        
        dfs(emp, id, visited);
        return count;
    }
};