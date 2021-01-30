# 98. Validate Binary Search Tree

```cpp
bool isValidBST(TreeNode* root) {
    if (!root) return true;

    if (root->left) {
        auto p = root->left;
        while (p->right)
            p = p->right;
        if (!(p->val < root->val))
            return false;
    }
    if (root->right) {
        auto p = root->right;
        while (p->left)
            p = p->left;
        if (!(root->val < p->val))
            return false;
    }
    return isValidBST(root->left) && isValidBST(root->right);
}
```
