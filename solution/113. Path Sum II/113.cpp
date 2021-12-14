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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& ans) {
        if (!node) return;
        
        target -= node->val;
        
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (target == 0)
                ans.push_back(path);
        } else {
            dfs(node->left, target, path, ans);
            dfs(node->right, target, path, ans);
        }
        path.pop_back();
    }
};
