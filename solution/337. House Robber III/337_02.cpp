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
        vector<int> ans = helper(root);
        return max(ans[0], ans[1]);
    }
    
private:
    vector<int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        
        vector<int> ans(2);
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = root->val + left[0] + right[0];
        return ans;
    }
};
