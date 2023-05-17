#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>>graph;
    void build(TreeNode* root, TreeNode* parent) {
        if (root && parent) {
            graph[root->val].push_back(parent->val);
            graph[parent->val].push_back(root->val);
        } 
        if (root->left)
            build(root->left, root);
        if (root->right)
            build(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root, NULL);
        unordered_map<int, bool>visited;
        queue<int>q;
        q.push(target->val);
        visited[target->val] = true;
        while(!q.empty() && k > 0) {
            int len = q.size();
            k--;
            for(int i = 0; i < len; i++) {
                int curr = q.front();
                q.pop();
                for(auto a: graph[curr]) {
                    if (!visited[a]) {
                        visited[a] = true;
                        q.push(a);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};