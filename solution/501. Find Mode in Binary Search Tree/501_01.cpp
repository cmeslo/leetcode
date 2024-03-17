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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> f;
        int mx = 0;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            mx = max(mx, ++f[node->val]);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);

        vector<int> res;
        for (auto& [k, v] : f) {
            if (v == mx)
                res.push_back(k);
        }
        return res;
    }
};
