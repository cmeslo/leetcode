# 111. Minimum Depth of Binary Tree


## 111_01.cpp

recursive

```cpp
int minDepth(TreeNode* root) {
    if (!root) return 0;

    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);

    if (left_depth == 0 || right_depth == 0)
        return 1 + left_depth + right_depth;

    return 1 + min(left_depth, right_depth);
}
```

## 111_02.cpp

bfs

```cpp
int minDepth(TreeNode* root) {
    if (!root) return 0;

    int min_depth = 1;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto* cur = q.front(); q.pop();
            if (!cur->left && !cur->right) return min_depth;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ++min_depth;
    }

    return min_depth;
}
```
