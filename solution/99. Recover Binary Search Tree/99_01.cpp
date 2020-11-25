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
        pre = nullptr, first = nullptr, second = nullptr;
        inOrderTraversal(root);
        swap(first->val, second->val);
    }
    
private:
    TreeNode *pre, *first, *second;
    
    void inOrderTraversal(TreeNode* root) {
        if (!root) return;
        if (root->left) inOrderTraversal(root->left);
        
        if (!pre) {
            pre = root;
        } else {
            if (pre->val > root->val) {
                if (!first) first = pre;
                second = root;
            }
        }
        pre = root;
        
        if (root->right) inOrderTraversal(root->right);
    }
};
