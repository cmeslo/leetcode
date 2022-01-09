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
    int maxProduct(TreeNode* root) {
        const int M = 1e9 + 7;
        dfs(root, 0);
        return ans_ % M;
    }
    
private:
    long ans_ = 0;
    
    unordered_map<TreeNode*, long> memo_;
    long get_sum(TreeNode* node) {
        if (!node) return 0;
        if (memo_.count(node)) return memo_[node];
        return memo_[node] = node->val + get_sum(node->left) + get_sum(node->right);
    }
    
    void dfs(TreeNode* node, long parent_sum) {
        if (!node) return;
        
        long cur_sum = parent_sum + node->val;
        long l = get_sum(node->left);
        long r = get_sum(node->right);
        
        ans_ = max(ans_, l * (cur_sum + r)); // split left
        ans_ = max(ans_, r * (cur_sum + l)); // split right
        
        dfs(node->left, cur_sum + r);
        dfs(node->right, cur_sum + l);
    }
};
