#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int answer = 0;
    int num;
    void backtrack(int path, int used) {
        if (path == num){
            answer++;
            return;
        }
        for(int i = 1; i <= num; i++){
            if ( (used & (1 << i)) == 0) {
                if ((path+1) % (i) == 0 || i % (path + 1) == 0) {
                    used |= (1 << i);
                    path++;
                    backtrack(path, used);
                    path--;
                    used ^= (1 << i);
                }
            }
        }
    }
    int countArrangement(int n) {
        num = n;
        backtrack(0, 0);
        return answer;
    }
};