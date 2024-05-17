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
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return res;
    }
    
private:
    int res = 0;
    
    pair<bool, int> dfs(TreeNode* node, int start) {
        if (!node) return {false, 0};
        
        auto [l_found, l_step] = dfs(node->left, start);
        auto [r_found, r_step] = dfs(node->right, start);
        
        if (node->val == start) {
            res = max({res, l_step, r_step});
            return {true, 0};
        }
        
        if (l_found) {
            res = max(res, l_step + r_step + 1);
            return {true, l_step + 1};
        } else if (r_found) {
            res = max(res, l_step + r_step + 1);
            return {true, r_step + 1};
        }
        
        return {false, max(l_step, r_step) + 1};
    }
};
