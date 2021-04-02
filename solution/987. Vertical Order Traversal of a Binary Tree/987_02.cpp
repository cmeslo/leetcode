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
        map<int, vector<PII>> m;
        dfs(root, 0, 0, m);
        
        vector<vector<int>> ans;
        for (auto& [x, list] : m) {
            sort(begin(list), end(list));
            vector<int> tmp;
            for (auto [level, val] : list)
                tmp.push_back(val);
            ans.push_back(tmp);
        }
        return ans;
    }
    
private:
    using PII = pair<int, int>; // {level, value}
    
    void dfs(TreeNode* node, int level, int x, map<int, vector<PII>>& m) {
        if (!node) return;
        m[x].push_back({level, node->val});
        dfs(node->left, level + 1, x - 1, m);
        dfs(node->right, level + 1, x + 1, m);
    }
};
