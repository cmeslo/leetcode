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
        long max_cnt = 0;
        
        queue<pair<TreeNode*, long>> q;
        
        q.push(pair<TreeNode*, int>{root, 1});
        while (!q.empty()) {
            long r = q.front().second, l = r;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, int>{node->left, r*2});
                if (node->right) q.push(pair<TreeNode*, int>{node->right, r*2+1});
            }
            max_cnt = max(max_cnt, r-l+1);
        }
        return max_cnt;
    }
};
