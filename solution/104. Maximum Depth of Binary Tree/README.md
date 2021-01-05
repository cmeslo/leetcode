# 104. Maximum Depth of Binary Tree

## bfs (104_01.cpp)

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;

    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto* cur = q.front(); q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ++depth;
    }

    return depth;
}
```

## dfs (104_02.cpp)

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```
