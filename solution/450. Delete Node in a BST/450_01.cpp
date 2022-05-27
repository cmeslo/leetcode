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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val == key) {
            if (root->left && root->right) {
                auto mn = root->right;
                while (mn->left)
                    mn = mn->left;
                root->val = mn->val;
                root->right = deleteNode(root->right, mn->val);
            } else {
                auto new_root = root->left ? root->left : root->right;
                delete root;
                return new_root;
            }
        }
        
        return root;
    }
};
