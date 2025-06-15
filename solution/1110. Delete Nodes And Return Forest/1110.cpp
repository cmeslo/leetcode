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

        dfs(root, true);
        return res;
    }
    
private:
    vector<TreeNode*> res;
    unordered_set<int> D;
    
    TreeNode* dfs(TreeNode* node, bool is_root) {
        if (!node) return nullptr;
        
        bool deleted = D.count(node->val);
        if (is_root && !deleted) res.push_back(node);
        
        node->left = dfs(node->left, deleted);
        node->right = dfs(node->right, deleted);
        
        return deleted ? nullptr : node;
    }
};
