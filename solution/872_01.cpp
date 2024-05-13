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
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        if (l1.size() != l2.size()) return false;
        return l1 == l2;
    }
    
    void dfs(TreeNode* node, vector<int>& A) {
        if (!node) return;
        
        if (!node->left && !node->right)
            A.push_back(node->val);
        
        dfs(node->left, A);
        dfs(node->right, A);
    }
};
