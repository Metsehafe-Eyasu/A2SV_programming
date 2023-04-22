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
    int total = 0;
    void calculate(TreeNode* node) {
        if (!node) return;
        if (node->right) total += node->right->val; 
        if (node->left) total += node->left->val; 
    }
    void dfs(TreeNode* node) {
        if (!node) return;
        if (node->val%2 == 0){
            calculate(node->left);
            calculate(node->right);
        }
        dfs(node->left);
        dfs(node->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return total;
    }
};