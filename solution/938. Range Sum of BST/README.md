# 938. Range Sum of BST

不剪枝

```cpp
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    int sum = low <= root->val && root->val <= high ? root->val : 0;
    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);
    return sum;
}
```

剪枝

```cpp
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    if (high < root->val) return rangeSumBST(root->left, low, high);
    if (root->val < low) return rangeSumBST(root->right, low, high);

    return root->val
        + rangeSumBST(root->left, low, high)
        + rangeSumBST(root->right, low, high);
}
```
