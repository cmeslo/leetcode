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
    TreeNode* convertBST(TreeNode* root) {
        int mx = 0;
        dfs(root, mx);
        return root;
    }
    
private:
    void dfs(TreeNode* node, int& mx) {
        if (!node) return;
        
        dfs(node->right, mx);
        mx = node->val += mx;
        dfs(node->left, mx);
    }
};
