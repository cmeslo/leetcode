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
        map<int, vector<pair<int, int>>> m;
        dfs(m, root, 0, 0);
        
        for (int i = min_l; i < max_r + 1; i++) {
            sort(m[i].begin(), m[i].end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
                return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
            });
            vector<int> cur;
            for (const auto& p : m[i])
                cur.push_back(p.second);
            ans.push_back(cur);
        }
        
        return ans;
    }
    
private:
    int min_l, max_r;
    
    void dfs(map<int, vector<pair<int, int>>>& m, TreeNode* node, int y, int x) {
        if (!node) return;
        
        m[x].push_back({y, node->val});
        
        min_l = min(min_l, x);
        max_r = max(max_r, x);
        
        dfs(m, node->left, y+1, x-1);
        dfs(m, node->right, y+1, x+1);
    }
};
