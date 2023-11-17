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
    int res = INT_MAX, val = -1;
    
    int getMinimumDifference(TreeNode* root) {
        if (root->left)
            getMinimumDifference(root->left);
        
        if (val != -1)
            res = min(res, root->val - val);
        val = root->val;
        
        if (root->right)
            getMinimumDifference(root->right);
        return res;
    }
};