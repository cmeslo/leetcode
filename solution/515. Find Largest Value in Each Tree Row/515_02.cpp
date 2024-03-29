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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;
        if (res.size() < level + 1) {
            res.push_back(node->val);
        } else {
            res[level] = max(res[level], node->val);
        }
        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);
    }
};
