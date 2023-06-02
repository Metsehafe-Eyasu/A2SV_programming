#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int index = n-2;
        while(index >= 0) {
            if (arr[index] > arr[index+1])
                break;   
            index--;
        }
        if (index < 0) return arr;
        int pos = index+1;
        for(int i = index+1; i < n; i++)
            if (arr[i] < arr[index] && arr[i] > arr[pos])
                pos = i;
        swap(arr[index], arr[pos]);
        return arr;
    }
};
