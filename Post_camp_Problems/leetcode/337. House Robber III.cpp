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
    unordered_map<int, int> memo;
    int dp(TreeNode* root, long long index) {
        if (!root)
            return 0;
        if (!memo[index]) {

            int val = root->val;
            if (root->left)
                val += dp(root->left->left, 4*index + 3) + dp(root->left->right, 4*index + 4); 
            if (root->right)
                val += dp(root->right->left, 4*index + 5) + dp(root->right->right, 4*index + 6); 
            int nxt = dp(root->left, 2*index + 1) + dp(root->right, 2*index + 2);
            memo[index] = max(val, nxt);     
        }
        return memo[index];
    }
    int rob(TreeNode* root) {
        return dp(root, 0);
    }
};