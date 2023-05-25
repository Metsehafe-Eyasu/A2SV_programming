#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int store5 = 0, store10 = 0;
        for(auto&bill: bills) {
            if (bill == 5) store5++;
            else if (bill == 10) {
                if (store5 > 0) {
                    store5--;
                    store10++;
                } else return false;
            }
            else {
                if (store10 >= 1 && store5 >= 1) {
                    store10--;
                    store5--;
                } else if (store5 > 2) store5 -= 3;
                else return false;
            }
        }
        return true;
    }
};
