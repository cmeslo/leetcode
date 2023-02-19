# 814. Binary Tree Pruning

```cpp
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return root;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if (!root->left && !root->right && root->val == 0)
        return nullptr;

    return root;
}
```
