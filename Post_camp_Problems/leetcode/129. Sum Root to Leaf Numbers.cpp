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
    int ans = 0;
    void dfs(TreeNode* node, int val) {
        if (!node) return;
        if (!node->right && !node->left) {
            ans += (val*10 + node->val);
            return;
        }

        dfs(node->right, val*10 + node->val);
        dfs(node->left, val*10 + node->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};