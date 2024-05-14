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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        st1.push(root1); st2.push(root2);
        while (!st1.empty() && !st2.empty()) {
            if (dfs(st1) != dfs(st2))
                return false;
        }
        return st1.empty() && st2.empty();
    }
    
    int dfs(stack<TreeNode*>& st) {
        while (true) {
            auto node = st.top(); st.pop();
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            if (!node->left && !node->right) return node->val;
        }
    }
};
