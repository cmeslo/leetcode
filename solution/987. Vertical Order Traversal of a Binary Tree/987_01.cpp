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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int, priority_queue<pair<int, int>>> m;
        dfs(m, root, 0, 0);
        
        for (int i = min_l; i <= max_r; i++) {
            if (m.find(i) == m.end()) continue;
            vector<int> cur(m[i].size());
            for (int j = m[i].size() - 1; j >= 0; j--) {
                cur[j] = m[i].top().second; m[i].pop();
            }
            ans.push_back(cur);
        }
        
        return ans;
    }
    
private:
    int min_l, max_r;
    
    void dfs(unordered_map<int, priority_queue<pair<int, int>>>& m, TreeNode* node, int y, int x) {
        if (!node) return;
        
        m[x].push({y, node->val});
        min_l = min(min_l, x);
        max_r = max(max_r, x);
        
        if (node->left) dfs(m, node->left, y+1 ,x-1);
        if (node->right) dfs(m, node->right, y+1 ,x+1);
    }
};
