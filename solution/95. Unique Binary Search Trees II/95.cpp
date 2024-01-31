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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) return { nullptr };

        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> L = dfs(start, i - 1);
            vector<TreeNode*> R = dfs(i + 1, end);
            for (auto& l : L) {
                for (auto& r : R) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
