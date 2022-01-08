# 1448. Count Good Nodes in Binary Tree

## Solution: DFS

```cpp
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    
private:
    int dfs(TreeNode* node, int mx) {
        if (!node) return 0;
        mx = max(mx, node->val);
        return (node->val >= mx)
            + dfs(node->left, mx)
            + dfs(node->right, mx);
    }
};
```

or

```cpp
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if (root) dfs(root, root->val, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, int mx, int& ans) {
        if (!node) return;
        if (node->val >= mx) ++ans;
        mx = max(mx, node->val);
        dfs(node->left, mx, ans);
        dfs(node->right, mx, ans);
    }
};
```
