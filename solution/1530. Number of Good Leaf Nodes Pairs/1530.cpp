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
    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        
        for (auto l : leaf)
            dfs2(l, nullptr, distance);
        
        return res / 2;
    }
    
private:
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> leaf;
    int res = 0;
    
    void dfs(TreeNode* node) {
        if (!node) return;
        
        if (node->left) {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            dfs(node->left);
        }
        
        if (node->right) {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            dfs(node->right);
        }
        
        if (!node->left && !node->right)
            leaf.insert(node);
    }
    
    void dfs2(TreeNode* node, TreeNode* prev, int d) {
        if (d == 0) return;
        
        for (auto next : adj[node]) {
            if (next == prev) continue;
            if (leaf.count(next))
                ++res;
            dfs2(next, node, d - 1);
        }
    }
};
