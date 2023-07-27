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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        int pre = 0;
        root->val = 1;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (++pre != node->val) return false;
            if (node->left) {
                node->left->val = node->val * 2;
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = node->val * 2 + 1;
                q.push(node->right);
            }
        }
        return true;
    }
};
