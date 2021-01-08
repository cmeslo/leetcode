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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        cur_ = &dummy;
        inorder(root);
        return dummy.right;
    }
    
private:
    TreeNode* cur_;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        
        root->left = nullptr;
        cur_->right = root;
        cur_ = root;
        
        inorder(root->right);
    }
};
