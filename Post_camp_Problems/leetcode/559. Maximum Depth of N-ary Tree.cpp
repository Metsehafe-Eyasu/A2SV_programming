#include <bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int count = 0;
    void dfs(Node* node, int c) {
        if (!node) return;

        count = max(count, c);
        for(auto& a: node->children) {
            dfs(a, c+1);
        }
    }
    int maxDepth(Node* root) {
        dfs(root, 1);
        return count;
    }
};