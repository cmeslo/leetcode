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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        dfs(root, res);
        return res;
    }
    
    const int INF = 1e9;
    
    pair<int, int> dfs(TreeNode* node, int& res) {
        if (!node) return {INF, -INF};
        auto [lmin, lmax] = dfs(node->left, res);
        auto [rmin, rmax] = dfs(node->right, res);
        res = min(res, node->val - lmax);
        res = min(res, rmin - node->val);
        return {min(node->val, lmin), max(node->val, rmax)};
    }
};
