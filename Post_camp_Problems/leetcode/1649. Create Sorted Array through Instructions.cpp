#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long MOD = 1e9 + 7;
    vector<pair<int, int>> arr;
    vector<int> lower, higher;
public:
    void merge(int left, int mid, int right) {
        for(int i = mid + 1, j = left, k = left; i <= right; i++) {
            while(j <= mid && arr[j].first < arr[i].first) j++;
            while(k <= mid && arr[k].first <= arr[i].first) k++;
            lower[arr[i].second] += j - left;
            higher[arr[i].second] += mid- k + 1;
        }
        vector<pair<int, int>> merged(right - left + 1);
        int l = left;
        int r = mid + 1;
        int placer = 0;
        while (l <= mid && r <= right) {
            if (arr[l].first <= arr[r].first) 
                merged[placer++] = arr[l++];
            else
                merged[placer++] = arr[r++];
        }

        while (l <= mid) {
            merged[placer++] = arr[l++];
        }
        while (r <= right) {
            merged[placer++] = arr[r++];
        }

        move(merged.begin(), merged.end(), arr.begin() + left);
    }

    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left)/2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        arr.resize(n);
        lower.resize(n);
        higher.resize(n);

        for (int i = 0; i < n; i++)
            arr[i] = {instructions[i], i};

        mergeSort(0, n - 1);

        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = (answer + min(lower[i], higher[i])) % MOD;
        }
        return answer;
    }
};