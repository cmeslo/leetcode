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
    // 寫法一
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;

        while (cur && cur->val != val) {
            cur = (val < cur->val) ? cur->left : cur->right;
        }
        return cur;
    }

    // 寫法二
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if (!root || root->val == val) return root;
    //     return searchBST(val < root->val ? root->left : root->right, val);
    // }
};
