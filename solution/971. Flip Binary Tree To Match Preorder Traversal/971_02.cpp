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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        st.push(root);
        int i = 0;
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            if (node->val != voyage[i++]) return {-1};
            if (node->left && node->left->val != voyage[i]) {
                ans.push_back(node->val);
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
            } else {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
        }
        return ans;
    }
};
