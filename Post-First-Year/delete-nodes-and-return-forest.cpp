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
    vector<TreeNode*> ans;
    bool dfs (TreeNode* node, bool take, set<int>& visit) {
        if (!node) return false;
        if (take && !visit.count(node->val)) ans.push_back(node);
        if (dfs(node->left, visit.count(node->val), visit)) node->left = nullptr;
        if (dfs(node->right, visit.count(node->val), visit)) node->right = nullptr;
        return visit.count(node->val);
    };
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>visit(to_delete.begin(), to_delete.end());
        dfs(root, true, visit);
        return ans;
    }
};