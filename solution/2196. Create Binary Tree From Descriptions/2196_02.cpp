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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> exclude;
        unordered_map<int, TreeNode*> m;
        for (auto& d : descriptions) {
            int root = d[0], child = d[1], isLeft = d[2];
            
            if (!m.count(root)) m[root] = new TreeNode(root);
            if (!m.count(child)) m[child] = new TreeNode(child);
            
            if (isLeft)
                m[root]->left = m[child];
            else
                m[root]->right = m[child];
            
            exclude.insert(child);
        }
        
        for (auto& d : descriptions)
            if (!exclude.count(d[0]))
                return m[d[0]];
        return nullptr;
    }
};
