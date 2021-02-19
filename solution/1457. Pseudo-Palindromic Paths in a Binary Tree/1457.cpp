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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* root, int f) {
        if (!root) return 0;
        
        int ans = 0;
        
        f ^= 1 << (root->val - 1);
        if (!root->left && !root->right)
            ans = (f & (f - 1)) == 0;
        else
            ans = dfs(root->left, f) + dfs(root->right, f);
        
        return ans;
    }
};
