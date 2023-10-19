#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int>arr;
    RandomizedSet() {}
    
    bool insert(int val) {
        if (hash.count(val)) return false;
        hash[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!hash.count(val)) return false;
        int n = arr.size();
        int ind = hash[val];
        swap(arr[n-1], arr[ind]);
        hash[arr[ind]] = ind;
        arr.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % arr.size();
        return arr[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */