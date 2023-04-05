#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int partition(vector<pair<int, int>> &arr, int left, int right)
    {
        int pivot = arr[right].second;
        int lower = left;
        for (int i = left; i < right; i++)
        {
            if (arr[i].second < pivot)
            {
                swap(arr[lower], arr[i]);
                lower++;
            }
        }
        swap(arr[lower], arr[right]);
        return lower;
    }

    void quick(vector<pair<int, int>> &arr, int left, int right)
    {
        if (left < right)
        {
            int pivot = partition(arr, left, right);
            quick(arr, left, pivot - 1);
            quick(arr, pivot + 1, right);
        }
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<pair<int, int>> count;
        unordered_map<int, int> count_map;
        for (auto &a : nums)
        {
            count_map[a]++;
        }
        for (auto &[key, value] : count_map)
        {
            count.push_back(make_pair(key, value));
        }
        quick(count, 0, count.size() - 1);
        vector<int> answer;
        cout << "here" << endl;
        int len = count.size() - 1;
        int i = 0;
        while (i < k)
        {
            answer.push_back(count[len - i].first);
            i++;
        }
        cout << "there" << endl;
        return answer;
    }
};