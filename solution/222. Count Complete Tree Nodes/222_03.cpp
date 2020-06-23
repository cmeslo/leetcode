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
        
        TreeNode *left_p = root, *right_p = root;
        int left_h = 0, right_h = 0;
        
        while (left_p) {
            left_h++;
            left_p = left_p->left;
        }
        while (right_p) {
            right_h++;
            right_p = right_p->right;
        }
        if (left_h == right_h) return pow(2, left_h)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
