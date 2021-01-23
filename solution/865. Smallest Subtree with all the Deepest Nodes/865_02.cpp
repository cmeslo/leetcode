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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans;
        depth(root, &ans);
        return ans;
    }

private:
    int depth(TreeNode* root, TreeNode** ans) {
        if (!root) return 0;
        
        TreeNode *pl, *pr;
        int left = depth(root->left, &pl);
        int right = depth(root->right, &pr);
        
        *ans = left == right ? root : left > right ? pl : pr;
        return 1 + max(left, right);
    }
};
