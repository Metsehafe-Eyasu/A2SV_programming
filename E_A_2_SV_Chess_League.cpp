#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> merge(vector<int>& arr, vector<int>& a, vector<int>& b, int k) {
    int i = 0, j = 0, m = 0;

    while ((i < a.size() && j < b.size()) && arr[b[0]] - arr[a[i]] > k) {
        i++;
    }
    while ((i < a.size() && j < b.size()) && arr[a[0]] - arr[b[j]] > k) {
        j++;
    }
    vector<int> c(a.size() + b.size() - i - j);
    while (i < a.size() && j < b.size()) {
        if (i < a.size() && arr[a[i]] <= arr[b[j]]) {
            c[m++] = a[i];
            i++;
        } else {
            c[m++] = b[j];
            j++;
        }
    }

    while (i < a.size()) {
        c[m++] = a[i];
        i++;
    }
    while (j < b.size()) {
        c[m++] = b[j];
        j++;
    }

    return c;
}
void display(vector<int>& a) {
    for (auto ind : a) {
        cout << ind + 1 << " ";
    }
    cout << endl;
}

vector<int> mergeSort(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        vector<int> a;
        a.push_back(left);
        return a;
    }

    int mid = left + (right - left) / 2;
    vector<int> a = mergeSort(arr, left, mid, k);
    vector<int> b = mergeSort(arr, mid + 1, right, k);
    return merge(arr, a, b, k);
}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int size = pow(2, n);
    vector<int> a(size);

    for (auto &i: a) {
        cin >> i;
    }

    vector<int> z = mergeSort(a, 0, size - 1, k);
    sort(z.begin(), z.end());
    display(z);
    return 0;
}
