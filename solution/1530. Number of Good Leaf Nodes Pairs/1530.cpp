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
        int res = 0;
        dfs(root, distance, res);
        return res;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& res) {
        vector<int> count(distance + 1);
        if (!node) return count;
        
        auto l = dfs(node->left, distance, res);
        auto r = dfs(node->right, distance, res);
        
        for (int i = 0; i < distance; ++i)
            for (int j = 0; i + j + 2 <= distance; ++j)
                res += l[i] * r[j];
        
        for (int i = 0; i < distance; ++i)
            count[i + 1] = l[i] + r[i];
        
        if (!node->left && !node->right)
            count[0] = 1;
        
        return count;
    }
};
