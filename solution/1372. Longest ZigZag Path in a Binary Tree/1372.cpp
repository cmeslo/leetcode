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
    int longestZigZag(TreeNode* root) {
        return dfs(root, 0, 0);
    }
    
private:
    int dfs(TreeNode* root, int left, int right) {
        if (!root) return max(left - 1, right - 1);
        
        return max(dfs(root->left, 0, left + 1),
                   dfs(root->right, right + 1, 0));
    }
};
