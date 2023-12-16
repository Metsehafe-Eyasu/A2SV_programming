class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> prefix(101, 0);
        for(int i = 0; i < logs.size(); i++) {
            prefix[logs[i][0] - 1950]++;
            prefix[logs[i][1] - 1950]--;
        }
        for(int i = 1; i < 101; i++) {
            prefix[i] += prefix[i-1];
        }
        int index = 0;
        for(int i = 0; i < 101; i++) {
            if (prefix[index] < prefix[i]) index = i;
        }
        return index + 1950;
    }
};