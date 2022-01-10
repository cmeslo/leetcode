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
    int maxProduct(TreeNode* root) {
        total_ = s(root);
        s(root);
        return ans_ % (int)(1e9 + 7);
    }
    
private:
    long ans_ = 0, total_ = 0;
    
    long s(TreeNode* node) {
        if (!node) return 0;
        long sub = node->val + s(node->left) + s(node->right);
        ans_ = max(ans_, sub * (total_ - sub));
        return sub;
    }
};
