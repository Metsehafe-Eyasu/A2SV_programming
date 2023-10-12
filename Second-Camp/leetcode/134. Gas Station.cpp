#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ptr = 0, runSum = 0, tank = 0;
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            runSum += gas[i] - cost[i]; 
            if (tank < 0) {
                ptr = i+1;
                tank = 0;
            }
        }
        return runSum >= 0 ? ptr : -1;
    }
};