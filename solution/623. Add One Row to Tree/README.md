# 623. Add One Row to Tree

## Solution 1 - BFS

```cpp
TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
        auto new_root = new TreeNode(v);
        new_root->left = root;
        return new_root;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        if (++depth == d - 1) {
            while (size--) {
                auto node = q.front(); q.pop();

                auto old_left = node->left;
                node->left = new TreeNode(v);
                node->left->left = old_left;

                auto old_right = node->right;
                node->right = new TreeNode(v);
                node->right->right = old_right;
            }
            break;
        } else {
            while (size--) {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }

    return root;
}
```
