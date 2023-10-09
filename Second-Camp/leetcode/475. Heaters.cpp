#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int m = houses.size();

        auto checker = [&] (int rad) {
            int index = 0;
            for(int house: houses) {
                while (index < n && abs(house - heaters[index]) > rad) index++;
                if (index == n) return false; 
            }
            return true;
        };

        int right = max(abs(heaters[n-1] - houses[0]), abs(houses[m-1] - heaters[0]));
        int left = 0;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (checker(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};