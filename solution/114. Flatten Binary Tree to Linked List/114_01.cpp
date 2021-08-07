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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        auto l = root->left;
        auto r = root->right;
        flatten(l);
        root->left = nullptr;
        if (l) {
            root->right = l;
            while (l && l->right)
                l = l->right;
            l->right = r;
        }
        flatten(r);
    }
};
