# 226. Invert Binary Tree

## Solution 1: DFS

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    swap(root->left, root->right);
    return root;
}
```
