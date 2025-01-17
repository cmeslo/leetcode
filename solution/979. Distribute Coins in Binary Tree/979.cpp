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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        balance(root, res);
        return res;
    }
    
    int balance(TreeNode* node, int& res) {
        if (!node) return 0;
        int l = balance(node->left, res);
        int r = balance(node->right, res);
        res += abs(l) + abs(r);
        return l + r + node->val - 1;
    }
};
