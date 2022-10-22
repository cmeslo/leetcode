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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode dummy;
        auto cur = &dummy;
        auto p = root;
        
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            
            cur->right = st.top(); st.pop();
            cur = cur->right;
            cur->left = nullptr;
            
            p = cur->right;
        }
        
        return dummy.right;
    }
};
