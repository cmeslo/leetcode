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
        if (!root) return root;
        
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val == key) {
            TreeNode* new_root;
            if (!root->left)
                new_root = root->right;
            if (!root->right)
                new_root = root->left;
            else {
                TreeNode* parent = root;
                new_root = root->right;
                while (new_root->left) {
                    parent = new_root;
                    new_root = new_root->left;
                }
                if (parent != root) {
                    parent->left = new_root->right;
                    new_root->right = root->right;
                }
                new_root->left = root->left;
            }
            delete root;
            return new_root;
        }
        
        return root;
    }
};
