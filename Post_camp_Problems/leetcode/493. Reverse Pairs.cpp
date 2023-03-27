#include<bits/stdc++.h>
using namespace std;

class Solution {
    int answer = 0;
    vector<int> merge(vector<int>& left, vector<int>& right) {
        int a = 0, b = 0;
        while (a < left.size() && b < right.size()) {
            if (left[a] > (long long)right[b]*2) {
                answer += left.size() - a;
                b++;
            } else 
                a++;
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
    int reversePairs(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return answer;
    }
};