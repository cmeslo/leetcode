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
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int res = INT_MAX;
        for (int i = 1; i < A.size(); ++i)
            res = min(res, A[i] - A[i - 1]);
        return res;
    }
    
private:
    vector<int> A;
    
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        A.push_back(node->val);
        dfs(node->right);
    }
};
