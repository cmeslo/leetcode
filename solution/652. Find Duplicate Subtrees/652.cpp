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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> res;
        for (auto [str, node] : m)
            res.push_back(node);
        return res;
    }

private:
    unordered_set<string> seen;
    unordered_map<string, TreeNode*> m;

    string dfs(TreeNode* node) {
        if (!node) return "";

        string l = dfs(node->left);
        string r = dfs(node->right);
        string cur = l + "-" + r + "-" + to_string(node->val);
        if (seen.count(cur))
            m[cur] = node;
        seen.insert(cur);
        return cur;
    }
};
