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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int d : to_delete)
            D.insert(d);
        
        if (!D.count(root->val))
            res.push_back(root);
        
        dfs(root);
        return res;
    }
    
private:
    vector<TreeNode*> res;
    unordered_set<int> D;
    
    TreeNode* dfs(TreeNode* node) {
        if (!node) return node;
        
        bool delete_me = D.count(node->val);
        if (delete_me) {
            if (node->left && !D.count(node->left->val))
                res.push_back(node->left);
            if (node->right && !D.count(node->right->val))
                res.push_back(node->right);
        }
        
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        
        return delete_me ? nullptr : node;
    }
};
