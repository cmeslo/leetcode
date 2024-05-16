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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        dfs(root, -1, adj);
        
        queue<int> q;
        unordered_map<int, int> seen;
        q.push(start);
        seen[start] = 1;
        
        int res = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int node = q.front(); q.pop();
                for (int next : adj[node]) {
                    if (!seen[next]++)
                        q.push(next);
                }
            }
            if (!q.empty()) res++;
        }
        return res;
    }
    
    void dfs(TreeNode* node, int pre, unordered_map<int, vector<int>>& adj) {
        if (!node) return;
        if (pre != -1)
            adj[node->val].push_back(pre);
        
        if (node->left) {
            adj[node->val].push_back(node->left->val);
            dfs(node->left, node->val, adj);
        }
        if (node->right) {
            adj[node->val].push_back(node->right->val);
            dfs(node->right, node->val, adj);
        }
    }
};
