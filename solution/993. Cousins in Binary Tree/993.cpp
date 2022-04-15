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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool isXExist = false, isYExist = false;
            for (int size = q.size(); size > 0; --size) {
                auto cur = q.front(); q.pop();
                if (cur->val == x) isXExist = true;
                if (cur->val == y) isYExist = true;
                if (cur->left && cur->right) {
                    if (cur->left->val == x && cur->right->val == y) return false;
                    if (cur->left->val == y && cur->right->val == x) return false;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (isXExist && isYExist) return true;
        }
        return false;
    }
};
