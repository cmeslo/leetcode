# 114. Flatten Binary Tree to Linked List

## Solution 1: Recursive

```cpp
void flatten(TreeNode* root) {
    if (!root) return;

    auto l = root->left;
    auto r = root->right;
    flatten(l);
    root->left = nullptr;
    if (l) {
        root->right = l;
        while (l && l->right)
            l = l->right;
        l->right = r;
    }
    flatten(r);
}
```
