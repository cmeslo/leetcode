# 543. Diameter of Binary Tree

## Solution: DFS

```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode* node, int& ans) {
        if (!node) return 0;
        int l = dfs(node->left, ans);
        int r = dfs(node->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};
```
