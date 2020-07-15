# 101. Symmetric Tree

## Recursive - 101_01.cpp
```cpp
bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;
    return isMirror(a->left, b->right)
        && isMirror(a->right, b->left);
}
```

## Iterative - 101_02.cpp
```cpp
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);

    while (!q.empty()) {
        auto* a = q.front(); q.pop();
        auto* b = q.front(); q.pop();
        if (!a && !b) continue;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        q.push(a->left);
        q.push(b->right);
        q.push(a->right);
        q.push(b->left);
    }
    return true;
}
```
