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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level_count = q.size();
            vector<int> temp(level_count);
            for (int i = 0; i < level_count; i++) {
                auto* cur = q.front(); q.pop();
                temp[i] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);    
            }
            ans.push_back(temp);
        }
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};
