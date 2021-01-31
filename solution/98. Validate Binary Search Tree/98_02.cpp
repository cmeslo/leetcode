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
        return dfs(root, nullptr, nullptr);
    }
    
private:
    bool dfs(TreeNode* root, TreeNode* upper_bound, TreeNode* lower_bound) {
        if (!root) return true;
        
        if (upper_bound && !(root->val < upper_bound->val)) return false;
        if (lower_bound && !(lower_bound->val < root->val)) return false;
        
        return dfs(root->left, root, lower_bound)
            && dfs(root->right, upper_bound, root);
    }
};
