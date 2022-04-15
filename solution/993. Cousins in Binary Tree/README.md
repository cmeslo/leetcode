# 993. Cousins in Binary Tree

## Solution: BFS

```cpp
bool isCousins(TreeNode* root, int x, int y) {
    TreeNode *x_parent = nullptr;
    TreeNode *y_parent = nullptr;
    int x_depth = 0, y_depth = 0;

    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({nullptr, root});
    int depth = 0;
    while (!q.empty()) {
        for (int size = q.size(); size > 0; --size) {
            auto [parent, cur] = q.front(); q.pop();
            if (cur->val == x) {
                x_parent = parent;
                x_depth = depth;
            }
            if (cur->val == y) {
                y_parent = parent;
                y_depth = depth;
            }
            if (x_parent && y_parent) {
                return x_parent != y_parent && x_depth == y_depth;
            }
            if (cur->left) q.push({cur, cur->left});
            if (cur->right) q.push({cur, cur->right});
        }
        ++depth;
    }
    return false;
}
```

or

```cpp
bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        bool isXExist = false, isYExist = false;
        for (int size = q.size(); size > 0; --size) {
            auto cur = q.front(); q.pop();
            if (cur->val == x) isXExist = true;
            if (cur->val == y) isYExist = true;
            if (cur->left && cur->right) {
                if (cur->left->val == x && cur->right->val == y) return false;
                if (cur->left->val == y && cur->right->val == x) return false;
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        if (isXExist && isYExist) return true;
    }
    return false;
}
```
