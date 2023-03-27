#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<int> merge(vector<int>& arr, int left, int right, int& answer) {
    if (left == right){
        vector<int>r;
        r.push_back(arr[left]);
        return r;
    }

    int mid = left + (right - left)/2;
    vector<int> l = merge(arr, left, mid, answer);
    vector<int> r = merge(arr, mid + 1, right, answer);
    vector<int> combined(right - left + 1);
    if (l[0] < r[0]) {
        for (int i = 0; i < l.size(); i++) {
            combined[i] = l[i];
        }
        for (int i = 0; i < r.size(); i++) {
            combined[i + l.size()] = r[i];
        }
    }
    else {
        answer++;
        for (int i = 0; i < r.size(); i++) {
            combined[i] = r[i];
        }
        for (int i = 0; i < l.size(); i++) {
            combined[i + r.size()] = l[i];
        }
    }
    return combined;
}

bool check(vector<int>arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


void solve() {
    int len;
    cin >> len;
    vector<int> arr(len);

    for (auto &i: arr) {
        cin >> i;
    }
    int answer = 0;
    vector<int> returned = merge(arr, 0, len - 1, answer);
    if (check(returned)) {
        cout << answer;
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    fast;
    int i;
    cin >> i;
    forn(_, i) {
        solve();
    }
}