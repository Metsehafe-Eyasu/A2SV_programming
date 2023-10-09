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
    unordered_map<string, int> count;
    vector<TreeNode*> ans;
    string encode(TreeNode* root) {
        if (!root) return "";
        string curr_encoding = to_string(root->val) + "#" + encode(root->right) + "#" + encode(root->left);
        if (++count[curr_encoding] == 2) ans.push_back(root);
        return curr_encoding;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        encode(root);
        return ans;
    }
};