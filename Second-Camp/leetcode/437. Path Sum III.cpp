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
    int answer = 0;
    vector<long long> stk;
    void DFS(TreeNode* node, int target, long long currSum) {
        if (!node) return;
        currSum += node->val;
        stk.push_back(currSum);
        for (int i = 0; i < stk.size() - 1; i++) {
            if (stk.back() - stk[i] == target)
                answer++;
        }
        DFS(node->left, target, currSum);
        DFS(node->right, target, currSum);
        stk.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        stk.push_back(0);
        DFS(root, targetSum, 0);
        return answer;
    }
};