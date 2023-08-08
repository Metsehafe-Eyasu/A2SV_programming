#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<long long> parent, size, sum_;
    UnionFind(int n, vector<int>& nums) : parent(n), size(n, 1), sum_(n) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++) {
            sum_[i] = nums[i];
        }
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    long long find_sum(int x) {
        x = find(x);
        return sum_[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        sum_[x] += sum_[y];
        return true;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> answer(n, 0);
        vector<bool>visited(n, false);
        UnionFind uf(n, nums);
        long long max_ = 0;
        for (int i=n-1; i >= 0; i--) {
            answer[i] = max_;
            int x = removeQueries[i];
            visited[x] = true;
            if (x+1 < n && visited[x+1]) {
                uf.unite(x, x+1);
            }
            if (x-1 >= 0 && visited[x-1]){
                uf.unite(x, x-1);
            }
            max_ = max(max_, uf.find_sum(x));
            cout << max_ <<endl;
        }
        return answer;
    }
};