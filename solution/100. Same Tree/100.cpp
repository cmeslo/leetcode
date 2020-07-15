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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both null
        if (!p && !q) return true;
        // one of them is null
        if (!p || !q) return false;
        // different value
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};
