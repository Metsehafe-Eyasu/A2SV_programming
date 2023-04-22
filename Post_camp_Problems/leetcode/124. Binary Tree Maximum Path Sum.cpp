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
    int maxCount = -2000;
    int traversal(TreeNode* node) {
        if (!node) return 0;
        int left = max(traversal(node->left), 0);
        int right = max(traversal(node->right), 0);
        int possibleVals[] = {left + int(node->val), right + int(node->val), left + right + int(node->val), int(node->val), maxCount};
        maxCount = *max_element(possibleVals, possibleVals+5);
        return max(right, left) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        traversal(root);
        return maxCount;
    }
};