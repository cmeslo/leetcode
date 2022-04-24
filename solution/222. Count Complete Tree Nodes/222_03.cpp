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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int left_h = 0, right_h = 0;
        auto p1 = root, p2 = root;
        while (p1) {
            ++left_h;
            p1 = p1->left;
        }
        while (p2) {
            ++right_h;
            p2 = p2->right;
        }
        
        if (left_h == right_h)
            return (1 << left_h) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
