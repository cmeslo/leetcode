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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left.second == right.second)
            return {root, left.second + 1};
        
        auto& ans = left.second > right.second ? left : right;
        return {ans.first, ans.second + 1};
    }
};
