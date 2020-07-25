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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        
        bool left = true;
        q.push_back(root);
        
        while (!q.empty()) {
            vector<int> cur;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node;
                if (left) {
                    node = q.front(); q.pop_front();
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                } else {
                    node = q.back(); q.pop_back();
                    if (node->right) q.push_front(node->right);
                    if (node->left) q.push_front(node->left);
                }
                cur.push_back(node->val);
            }
            ans.push_back(cur);
            left = !left;
        }
        return ans;
    }
};
