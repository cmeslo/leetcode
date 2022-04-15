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
        TreeNode *x_parent = nullptr;
        TreeNode *y_parent = nullptr;
        int x_depth = 0, y_depth = 0;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        int depth = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                auto [parent, cur] = q.front(); q.pop();
                if (cur->val == x) {
                    x_parent = parent;
                    x_depth = depth;
                }
                if (cur->val == y) {
                    y_parent = parent;
                    y_depth = depth;
                }
                if (x_parent && y_parent) {
                    return x_parent != y_parent && x_depth == y_depth;
                }
                if (cur->left) q.push({cur, cur->left});
                if (cur->right) q.push({cur, cur->right});
            }
            ++depth;
        }
        return false;
    }
};
