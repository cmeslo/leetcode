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
        dfs(root, 0, 0);
        return res;
    }
    
private:
    int res = 0;
    
    void dfs(TreeNode* root, int left, int right) {
        if (!root) {
            res = max({res, left - 1, right - 1});
            return;
        }
        
        dfs(root->left, 0, left + 1);
        dfs(root->right, right + 1, 0);
    }
};
