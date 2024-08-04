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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int increasing = true;
        while (!q.empty()) {
            int pre = increasing ? 0 : 1e6 + 1;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front(); q.pop();
                if (increasing) {
                    if (pre >= node->val || node->val % 2 == 0)
                        return false;
                } else {
                    if (pre <= node->val || node->val % 2 == 1)
                        return false;
                }
                pre = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            increasing = !increasing;
        }
        return true;
    }
};
