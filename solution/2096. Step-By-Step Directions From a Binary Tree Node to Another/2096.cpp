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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);

        string startPath, destPath;
        dfs(lca, startValue, startPath);
        dfs(lca, destValue, destPath);

        return string(startPath.size(), 'U') + destPath;
    }
    
    TreeNode* LCA(TreeNode* node, int start, int dest) {
        if (!node) return node;
        if (node->val == start || node->val == dest) return node;
        
        auto l = LCA(node->left, start, dest);
        auto r = LCA(node->right, start, dest);
        
        if (l && r) return node;
        return l ? l : r;
    }

    bool dfs(TreeNode* node, int val, string& path) {
        if (!node) return false;

        if (node->val == val) return true;

        path.push_back('L');
        bool l = dfs(node->left, val, path);
        if (l) return true;
        path.pop_back();

        path.push_back('R');
        bool r = dfs(node->right, val, path);
        if (r) return true;
        path.pop_back();

        return false;
    }
};
