# 971. Flip Binary Tree To Match Preorder Traversal

## Solution 1 - DFS

```cpp
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int i = 0;
        return dfs(root, voyage, i, ans) ? ans : vector<int> {-1};
    }
    
private:
    bool dfs(TreeNode* node, vector<int>& v, int& i, vector<int>& ans) {
        if (!node) return true;
        if (node->val != v[i++]) return false;
        
        if (node->left && node->left->val != v[i]) {
            ans.push_back(node->val);
            return dfs(node->right, v, i, ans) && dfs(node->left, v, i, ans);
        }
        return dfs(node->left, v, i, ans) && dfs(node->right, v, i, ans);
    }
};
```
