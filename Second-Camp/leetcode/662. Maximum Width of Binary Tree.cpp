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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 1;
        queue<pair<TreeNode*, int>> level;
        level.push({root, 0});

        while (!level.empty()) {
            int len = level.size();
            int left = level.front().second;
            int right = level.back().second;
            maxWidth = max(maxWidth, right - left + 1);
            while (len--) {
                pair<TreeNode*, int> curr = level.front();
                level.pop();

                int index = curr.second - right;
                if (curr.first->left) 
                    level.push({curr.first->left, (long long)2*index + 1 });
                if (curr.first->right) 
                    level.push({curr.first->right, (long long)2*index + 2 });
                
            }
        }
        return maxWidth;
    }
};