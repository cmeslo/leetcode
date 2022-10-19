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
