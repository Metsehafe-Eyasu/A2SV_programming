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
    string dfs(TreeNode* node) {
        string r = to_string(node->val);
        if (node->left != NULL) {
            r += "(" + dfs(node->left) + ")";
        } else if (node->left == NULL && node->right != NULL){
            r+= "()";
        }
        if (node->right !=  NULL) {
            r += "(" + dfs(node->right) + ")";
        }
        return r;
    } 
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};