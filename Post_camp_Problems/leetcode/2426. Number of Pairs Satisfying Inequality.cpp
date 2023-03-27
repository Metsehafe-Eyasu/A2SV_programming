#include<bits/stdc++.h>
using namespace std;
class Solution {
    long long answer = 0;
    int diff;
    vector<int> merge(vector<int>& left, vector<int>& right) {
        int a = 0, b = 0;
        while (a < left.size() && b < right.size()) {
            if (left[a] <= right[b] + diff) {
                answer += right.size() - b;
                a++;
            } else 
                b++;
        }
        vector<int> result(left.size() + right.size());
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result[k++] = left[i++];
            }
            else {
                result[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            result[k++] = left[i++];
        }
        while (j < right.size()) {
            result[k++] = right[j++];
        }
        return result;
    }

    vector<int> mergeSort(int left, int right, vector<int>& arr) {
        if (left == right) {
            return vector<int>(1, arr[left]);
        }
        int mid = (left + right) / 2;
        vector<int> leftArr = mergeSort(left, mid, arr);
        vector<int> rightArr = mergeSort(mid + 1, right, arr);
        return merge(leftArr, rightArr);
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        this->diff = diff;
        vector<int> comb(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            comb[i] = nums1[i] - nums2[i];
        }
        vector<int> fin = mergeSort(0, comb.size() - 1, comb);
        return answer;
    }
};