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
    int res = 1;
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto node = q.front(); q.pop();
            if (!node->left && !node->right) return res;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++res;
    }
    return 0;
}
```
