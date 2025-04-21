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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> A;
        dfs(root, A);
        return build(A, 0, A.size() - 1);
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*>& A) {
        if (!node) return;
        dfs(node->left, A);
        A.push_back(node);
        dfs(node->right, A);
    }
    
    TreeNode* build(vector<TreeNode*>& A, int l, int r) {
        if (l > r) return nullptr;
        
        int mid = l + (r - l) / 2;
        auto node = A[mid];
        node->left = build(A, l, mid - 1);
        node->right = build(A, mid + 1, r);
        return node;
    }
};
