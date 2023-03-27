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
    TreeNode* contructor(TreeNode* parent, int insertVal) {
        if (!parent) {
            return new TreeNode(insertVal);
        }
        if (parent->val > insertVal) {
            parent->left = contructor(parent->left, insertVal);
        } else {
            parent->right = contructor(parent->right, insertVal);
        }
        return parent;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            contructor(head, preorder[i]);
        }
        return head;
    }
};