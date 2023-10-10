#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool preorder(TreeNode* root, long minval, long maxval) {
        if (!root) return true;
        if (root->val >= maxval || root->val <= minval) return false;
        bool left = preorder(root->left, minval, root->val);
        bool right = preorder(root->right, root->val, maxval);
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        return preorder(root, LONG_MIN, LONG_MAX);
    }
};
