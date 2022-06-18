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
    int rob(TreeNode* root) {
        auto ans = dp(root);
        return max(ans.first, ans.second);
    }
    
private:
    pair<int, int> dp(TreeNode* node) { // rob node, pass node
        if (!node) return {0, 0};
        
        auto l = dp(node->left);
        auto r = dp(node->right);
        
        return {node->val + l.second + r.second,
                max(l.first, l.second) + max(r.first, r.second)};
    }
};
