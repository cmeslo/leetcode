# 226. Invert Binary Tree

## Solution 1: DFS

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    swap(root->left, root->right);
    return root;
}
```

## Solution 2: BFS

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        swap(cur->left, cur->right);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return root;
}
```
