#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b, int k) {
    vector<int> c;
    int i = 0, j = 0;
    int minLeft = a[0];
    int minRight = b[0];
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            if (minRight - a[i] <= k)
                c.push_back(a[i]);
            i++;
        } else {
            if (minLeft - b[j] <= k)
                c.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size() && minRight - a[i] <= k) {
        c.push_back(a[i]);
        i++;
    }
    while (j < b.size() && minLeft - b[j] <= k) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> mergeSort(vector<int> arr, int right, int left, int k) {
    if (right == left) {
        vector<int> a;
        a.push_back(arr[right]);
        return a;
    }
    int mid = (right + left) / 2;
    vector<int> a = mergeSort(arr, right, mid, k);
    vector<int> b = mergeSort(arr, mid + 1, left, k);
    return merge(a, b, k);
}

void display(vector<int> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    int size = pow(2, n);
    vector<int> a(size);

    for (auto &i : a) {
        cin >> i;
    }
    display(mergeSort(a, 0, size - 1, k));
    return 0;
}
