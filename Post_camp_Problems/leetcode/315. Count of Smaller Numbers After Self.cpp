#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<pair<int, int>> merge(vector<int>& count, vector<pair<int, int>>& left, vector<pair<int, int>>& right) {
        vector<pair<int, int>> result(left.size() + right.size());
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                count[left[i].second] += j;
                result[k] = left[i++];
            }
            else {
                result[k] = right[j++];
            }
            k++;        
        }
        while (i < left.size()) {
            count[left[i].second] += j;
            result[k++] = left[i++];
        }
        while (j < right.size()) {
            result[k++] = right[j++];
        }
        return result;
    }

    vector<pair<int, int>> mergeSort(vector<int>& count, int left, int right, vector<pair<int, int>>& arr) {
        if (left == right) {
            return vector<pair<int,int>>{arr[left]};
        }
        int mid = (left + right) / 2;
        vector<pair<int, int>> leftArr = mergeSort(count, left, mid, arr);
        vector<pair<int, int>> rightArr = mergeSort(count, mid + 1, right, arr);
        return merge(count, leftArr, rightArr);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();

        vector<pair<int, int>> paired(len);
        for(int i = 0; i < len; i++) {
            paired[i] = make_pair(nums[i], i);
        }

        vector<int>count(len, 0);
        mergeSort(count, 0, len - 1, paired);
        return count;
    }
};