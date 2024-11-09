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
    string smallestFromLeaf(TreeNode* root, string s = "") {
        if (!root) return "|";
        
        s = string(1, root->val + 'a') + s;
        
        // if (!root->left && !root->right)
        if (root->left == root->right)
            return s;
        
        return min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s));
    }
};
