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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return dfs(root, v, d, true);
    }
    
private:
    TreeNode* dfs(TreeNode* node, int v, int d, bool isLeft) {
        if (d == 1) {
            auto new_node = new TreeNode(v);
            (isLeft ? new_node->left : new_node->right) = node;
            return new_node;
        }
        if (!node) return node;
        
        node->left = dfs(node->left, v, d - 1, true);
        node->right = dfs(node->right, v, d - 1, false);
        
        return node;
    }
};
