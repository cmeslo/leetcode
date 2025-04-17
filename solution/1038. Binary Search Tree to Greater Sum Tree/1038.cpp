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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> A;
        dfs(root, A);
        
        const int n = A.size();
        vector<int> presum(n);
        presum[0] = A[0];
        for (int i = 1; i < n; ++i)
            presum[i] = presum[i - 1] + A[i];
        
        dfs2(root, A, presum);
        return root;
    }
    
private:
    void dfs(TreeNode* node, vector<int>& A) {
        if (!node) return;
        
        if (!node->left && !node->right) {
            A.push_back(node->val);
            return;
        }
        
        if (node->left) dfs(node->left, A);
        A.push_back(node->val);
        if (node->right) dfs(node->right, A);
    }
    
    void dfs2(TreeNode* node, vector<int>& A, vector<int>& presum) {
        if (!node) return;
        
        int i = upper_bound(A.begin(), A.end(), node->val) - A.begin();
        node->val += presum.back() - (i - 1 >= 0 ? presum[i - 1] : 0);
        
        dfs2(node->left, A, presum);
        dfs2(node->right, A, presum);
    }
};
