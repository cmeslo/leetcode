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
    int pathSum(TreeNode* root, int sum) {
        _ans = 0;
        _prefixSum = {{0, 1}};
        
        pathSum(root, 0, sum);
        return _ans;
    }

private:
    int _ans;
    unordered_map<int, int> _prefixSum;
    
    void pathSum(TreeNode* node, int cur, int sum) {
        if (!node) return;
        
        cur += node->val;
        _ans += _prefixSum[cur - sum];
        
        _prefixSum[cur]++;
        pathSum(node->left, cur, sum);
        pathSum(node->right, cur, sum);
        _prefixSum[cur]--;
    }
};
