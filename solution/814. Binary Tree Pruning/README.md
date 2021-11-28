# 814. Binary Tree Pruning

```cpp
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return nullptr;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if (root->val == 1)
        return root;
    else
        return root->left || root->right ? root : nullptr;
}
```
