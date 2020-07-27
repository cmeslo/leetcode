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
        return buildTree(inorder, 0, inorder.size()-1, postorder);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder) {
        if (inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                root->right = buildTree(inorder, i+1, inEnd, postorder);
                root->left = buildTree(inorder, inStart, i-1, postorder);
                break;
            }
        }
        return root;
    }
};
