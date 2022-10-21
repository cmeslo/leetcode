# 700. Search in a Binary Search Tree

## Solution 1

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* cur = root;

    while (cur && cur->val != val) {
        cur = (val < cur->val) ? cur->left : cur->right;
    }
    return cur;
}
```

## Solution 2: Recursion

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return searchBST(val < root->val ? root->left : root->right, val);
}
```
