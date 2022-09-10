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
    int widthOfBinaryTree(TreeNode* root) {
        long ans = 1;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            long left = q.front().second, right = left;
            int size = q.size();
            while (size--) {
                auto [node, x] = q.front(); q.pop();
                right = x;
                if (node->left) q.push({node->left, x * 2 - 1 - left});
                if (node->right) q.push({node->right, x * 2 - left});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
