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
    int findBottomLeftValue(TreeNode* root) {
        res = root->val;
        dfs(root, 0);
        return res;
    }
    
private:
    int maxDepth = 0;
    int res;
    
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        
        if (depth > maxDepth) {
            maxDepth = depth;
            res = node->val;
        }
    }
};
