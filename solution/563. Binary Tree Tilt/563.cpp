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
    int findTilt(TreeNode* root) {
        int ans = 0;
        postOrderTraversal(root, ans);
        return ans;
    }

private:
    int postOrderTraversal(TreeNode* root, int& ans) {
        if (!root) return 0;
        int leftSum = postOrderTraversal(root->left, ans);
        int rightSum = postOrderTraversal(root->right, ans);
        ans += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
};
