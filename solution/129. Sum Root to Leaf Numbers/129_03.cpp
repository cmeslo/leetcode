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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (!node->left && !node->right)
                res += node->val;
            if (node->left) {
                node->left->val += node->val * 10;
                q.push(node->left);
            }
            if (node->right) {
                node->right->val += node->val * 10;
                q.push(node->right);
            }
        }
        return res;
    }
};
