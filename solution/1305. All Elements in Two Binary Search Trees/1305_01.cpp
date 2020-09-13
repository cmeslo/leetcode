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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        list1.insert(list1.end(), list2.begin(), list2.end());
        sort(list1.begin(), list1.end());
        return list1;
    }
    
private:
    void dfs(TreeNode* node, vector<int>& list) {
        if (!node) return;
        
        list.push_back(node->val);
        dfs(node->left, list);
        dfs(node->right, list);
    }
};
