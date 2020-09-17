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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string cur = "";
        dfs(root, cur, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, string& cur, int& ans) {
        if (!node) return;
        
        cur.append(to_string(node->val));
        
        if (!node->left && !node->right) {
            ans += stoi(cur, nullptr, 2);
        } else {
            dfs(node->left, cur, ans);
            dfs(node->right, cur, ans);
        }
        
        cur.pop_back();
    }
};
