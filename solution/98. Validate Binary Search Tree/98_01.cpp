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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        if (root->left) {
            auto p = root->left;
            while (p->right)
                p = p->right;
            if (!(p->val < root->val))
                return false;
        }
        if (root->right) {
            auto p = root->right;
            while (p->left)
                p = p->left;
            if (!(root->val < p->val))
                return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
