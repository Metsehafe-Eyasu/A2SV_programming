#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void search (TreeNode* root, int val, vector<TreeNode*>& arr) {
        if (!root) return;
        arr.push_back(root);
        if (arr.back()->val == val) return;
        if (arr.back()->val != val) search(root->right, val, arr);
        if (arr.back()->val != val) search(root->left, val, arr);
        if (arr.back()->val != val) arr.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ppath, qpath;
        search(root, p->val, ppath);
        search(root, q->val, qpath);

        int len = min(ppath.size(), qpath.size());
        int i = 0;
        for(auto a: ppath) cout << a->val << " ";
        cout << endl;
        for(auto a: qpath) cout << a->val << " ";
        cout << endl;
        for(i = 0; i < len && ppath[i]->val == qpath[i]->val; i++) {}
        cout << i;
        return ppath[--i];
    }
};