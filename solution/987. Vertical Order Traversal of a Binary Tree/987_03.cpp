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
        if (!root) return {};
        
        map<int, vector<pair<int, int>>> m; // x -> [{y1, val1}, {y2, val2}]
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int y = 0;
        int x_min = 0, x_max = 0;
        
        while (!q.empty()) {
            int size = q.size();
            ++y;
            while (size--) {
                auto [x, node] = q.front(); q.pop();
                m[x].push_back({y, node->val});
                x_min = min(x_min, x);
                x_max = max(x_max, x);
                if (node->left) q.push({x - 1, node->left});
                if (node->right) q.push({x + 1, node->right});
            }
        }
        
        vector<vector<int>> ans;
        for (int i = x_min; i <= x_max; ++i) {
            vector<int> cur;
            sort(begin(m[i]), end(m[i]), [&](auto& a, auto& b) {
                return (a.first < b.first) || (a.first == b.first && a.second < b.second);
            });
            for (const auto& [x, val] : m[i])
                cur.push_back(val);
            ans.push_back(cur);
        }
        return ans;
    }
};
