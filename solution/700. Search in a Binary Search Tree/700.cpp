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
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     TreeNode* cur = root;
        
    //     while (cur != nullptr) {
    //         if (cur->val == val) {
    //             return cur;
    //         } else {
    //             cur = (val < cur->val) ? cur->left : cur->right;
    //         }
    //     }
    //     return nullptr;
    // }

    // 寫法二
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;

        while (cur && cur->val != val) {
            cur = (val < cur->val) ? cur->left : cur->right;
        }
        return cur;
    }

    // 寫法三
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if (!root) return nullptr;
    //     if (root->val == val) return root;
    //     if (root->val > val) {
    //         return searchBST(root->left, val);
    //     } else {
    //         return searchBST(root->right, val);
    //     }        
    // }
};
