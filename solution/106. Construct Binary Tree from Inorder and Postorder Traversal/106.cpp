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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        int pRoot = postorder.size() - 1;
        return buildTree(m, 0, inorder.size()-1, postorder, pRoot);
    }
    
private:
    TreeNode* buildTree(unordered_map<int, int>& m, int inStart, int inEnd, vector<int>& postorder, int& pRoot) {
        if (inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[pRoot--]);

        root->right = buildTree(m, m[root->val]+1, inEnd, postorder, pRoot);
        root->left = buildTree(m, inStart, m[root->val]-1, postorder, pRoot);

        return root;
    }
};
