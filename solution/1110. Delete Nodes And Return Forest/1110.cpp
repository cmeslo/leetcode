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
        
        if (D.count(node->val)) {
            if (node->left) {
                if (!D.count(node->left->val))
                    res.push_back(node->left);
                node->left = dfs(node->left);
            }
            if (node->right) {
                if (!D.count(node->right->val))
                    res.push_back(node->right);
                node->right = dfs(node->right);
            }
            return nullptr;
        }
        
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        return node;
    }
};
