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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        
        return pathSum(root->left, sum)
            + pathSum(root->right, sum)
            + pathSumWithRoot(root, sum);
    }

private:
    int pathSumWithRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        
        return (root->val == sum ? 1 : 0)
            + pathSumWithRoot(root->left, sum - root->val)
            + pathSumWithRoot(root->right, sum - root->val);
    }
};
