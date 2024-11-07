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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        string res = "";
        queue<pair<TreeNode*, string>> q;
        q.push({root, string(1, root->val + 'a')});
        while (!q.empty()) {
            auto [node, s] = q.front(); q.pop();
            if (!node->left && !node->right) {
                reverse(s.begin(), s.end());
                if (res.empty() || s < res)
                    res = s;
            }
            if (node->left)
                q.push({node->left, s + string(1, node->left->val + 'a')});
            if (node->right)
                q.push({node->right, s + string(1, node->right->val + 'a')});
        }
        return res;
    }
};
