# 701. Insert into a Binary Search Tree

## Solution 1: Recursion

```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else if (root->val < val)
        root->right = insertIntoBST(root->right, val);

    return root;
}
```

## Solution 2: Iteration

```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = new TreeNode(val);
    if (!root) return node;

    auto cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left)
                cur = cur->left;
            else {
                cur->left = node;
                break;
            }
        } else {
            if (cur->right)
                cur = cur->right;
            else {
                cur->right = node;
                break;
            }
        }
    }

    return root;
}
```

or

```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    auto node = new TreeNode(val);
    if (!root) return node;
    TreeNode *pre = nullptr, *cur = root;
    while (cur) {
        pre = cur;
        if (val < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (val < pre->val)
        pre->left = node;
    else
        pre->right = node;
    return root;
}
```
