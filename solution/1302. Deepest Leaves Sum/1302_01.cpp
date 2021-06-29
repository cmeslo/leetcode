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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int depth_max = 1;
        dfs(root, 1, depth_max, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, int depth, int& depth_max, int& ans) {
        if (!node) return;
        
        if (depth > depth_max) {
            depth_max = depth;
            ans = node->val;
        } else if (depth == depth_max) {
            ans += node->val;
        }
        
        dfs(node->left, depth + 1, depth_max, ans);
        dfs(node->right, depth + 1, depth_max, ans);
    }
};
