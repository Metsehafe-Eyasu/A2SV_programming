#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int left = 0, right = len-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (mountainArr.get(mid) > mountainArr.get(mid+1))
                right = mid;
            else 
                left = mid + 1; 
        }
        int center = left;
        left = 0; right = center;
        while(left < right) {
            int mid = left + (right - left)/2;
            if (mountainArr.get(mid) >= target)
                right = mid;
            else 
                left = mid + 1; 
        }
        if (mountainArr.get(left) == target) return left;
        left = center; right = len-1;
        while(left < right) {
            int mid = left + (right - left)/2;
            int val = mountainArr.get(mid);
            if (val == target) return mid; 
            if (val > target)
                left = mid+1;
            else 
                right = mid-1;
        }
        if (mountainArr.get(right) == target) return right;
        return -1;
    }
};