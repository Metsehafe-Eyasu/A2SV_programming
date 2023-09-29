#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;    
    vector<Node*>children;
    Node () : val(0), children(26, NULL) {}
};
class MapSum {
    unordered_map<string, int>memo;
    Node* root;
public:
    MapSum() : root(new Node()) {}
    
    void insert(string key, int val) {
        int num = val;
        if (memo.count(key)) num -= memo[key];
        memo[key] = val;
        Node* placer = root;
        for(char ch: key) {
            int index = ch - 'a';
            if (!placer->children[index]) 
                placer->children[index] = new Node();
            placer->children[index]->val += num;
            placer = placer->children[index];
        }
    }
    
    int sum(string prefix) {
        Node* finder = root;
        for(char ch: prefix) {
            int index = ch - 'a';
            if (!finder->children[index]) return 0;
            finder = finder->children[index];
        }
        return finder ? finder->val : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */