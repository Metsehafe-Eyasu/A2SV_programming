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
    int ans;
    int dfs (TreeNode* root) {
        if (!root) return 0;
        int right = dfs(root->right), val = 0, left = dfs(root->left);
        if (root->val) 
          val = root->val - 1;
        else 
          val = -1;
          
        val += right + left;
        ans += abs(right) + abs(left);
        return val;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};