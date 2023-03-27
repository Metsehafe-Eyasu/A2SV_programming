class Solution {
public:
    int answer = 0;
    void backtrack(vector<vector<int>>& requests, vector<int>& buildings, int index, int count) {
        if (index >= requests.size()) {
            bool check = true;
            for (auto& a: buildings) {
                if (a != 0) {
                    check = false;
                    break;
                }
            }
            if (check) 
                answer = max(answer, count);
            return;
        }
        int from = requests[index][0];
        int to = requests[index][1];
        buildings[from]++;
        buildings[to]--;
        backtrack(requests, buildings, index + 1, count + 1);
        buildings[from]--;
        buildings[to]++;
        backtrack(requests, buildings, index + 1, count);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>buildings(n, 0);
        backtrack(requests, buildings, 0, 0);
        return answer;
    }
};