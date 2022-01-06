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
