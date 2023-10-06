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
    vector<int>_stack;
    vector<vector<int>>ans;
    void dfs(int curr, TreeNode* node, int target) {
        _stack.push_back(node->val);
        curr += node->val;
        if (!node->left && !node->right && curr == target) ans.push_back(_stack);
        if (node->left) dfs(curr, node->left, target);
        if (node->right) dfs(curr, node->right, target);
        _stack.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root) dfs(0, root, targetSum);
        return ans;
    }
};