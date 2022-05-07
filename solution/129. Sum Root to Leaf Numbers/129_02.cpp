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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            if (cur->left) {
                while (cur && cur->left) {
                    if (cur->right)
                        st.push(cur->right);
                    cur = cur->left;
                }
                if (!cur->right)
                    res += cur->val;
            }
            if (cur->right)
                st.push(cur->right);
        }
        
        return res;
    }
};
