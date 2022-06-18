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
    int rob(TreeNode* root) {
        return max(rob(root, true), rob(root, false));
    }
    
    int rob(TreeNode* root, bool isRob) {
        if (!root) return 0;
        
        if (isRob) {
            if (dpRob.count(root)) return dpRob[root];
            return dpRob[root] = root->val + rob(root->left, false) + rob(root->right, false);
        } else {
            if (dpPass.count(root)) return dpPass[root];
            return dpPass[root] = max(rob(root->left, true), rob(root->left, false))
                + max(rob(root->right, true), rob(root->right, false));
        }
    }
    
private:
    unordered_map<TreeNode*, int> dpRob;
    unordered_map<TreeNode*, int> dpPass;
};
