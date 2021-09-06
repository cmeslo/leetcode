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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            pos_[inorder[i]] = i;
        int i = 0;
        return dfs(preorder, i, inorder, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> pos_;
    
    TreeNode* dfs(vector<int>& preorder, int& i, vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;
        
        int val = preorder[i++];
        auto root = new TreeNode(val);
        int m = pos_[val];
        root->left = dfs(preorder, i, inorder, l, m - 1);
        root->right = dfs(preorder, i, inorder, m + 1, r);
        return root;
    }
};
