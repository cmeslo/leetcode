/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        
        unordered_map<int, vector<int>> adj;
        dfs(root, -1, adj);
        
        vector<int> res;
        queue<int> q;
        unordered_set<int> seen;
        seen.insert(target->val);
        q.push(target->val);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                if (k == 0) {
                    res.push_back(node);
                }
                for (int next : adj[node]) {
                    if (seen.count(next)) continue;
                    seen.insert(next);
                    q.push(next);
                }
            }
            if (k-- == 0) break;
        }
        return res;
    }
    
    void dfs(TreeNode* node, int pre, unordered_map<int, vector<int>>& adj) {
        if (!node) return;
        if (pre != -1) {
            adj[node->val].push_back(pre);
            adj[pre].push_back(node->val);
        }
        if (node->left) {
            dfs(node->left, node->val, adj);
        }
        if (node->right) {
            dfs(node->right, node->val, adj);
        }
    }
};
