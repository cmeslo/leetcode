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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;
        
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                auto *tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                    continue;
                } else { // left child finished
                    tmp->right = nullptr;
                }
            }
            // cout << cur->val << ", ";
            if (pre && pre->val > cur->val) {
                if (!first) first = pre;
                second = cur;
            }
            pre = cur;

            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
