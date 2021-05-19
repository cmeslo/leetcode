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

## Solution 2 - DFS

```cpp
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return dfs(root, v, d, true);
    }
    
private:
    TreeNode* dfs(TreeNode* node, int v, int d, bool isLeft) {
        if (d == 1) {
            auto new_node = new TreeNode(v);
            (isLeft ? new_node->left : new_node->right) = node;
            return new_node;
        }
        if (!node) return node;
        
        node->left = dfs(node->left, v, d - 1, true);
        node->right = dfs(node->right, v, d - 1, false);
        
        return node;
    }
};
```

or

```cpp
TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 0 || d == 1) { // 1: left, 0: right
        auto new_root = new TreeNode(v);
        (d ? new_root->left : new_root->right) = root;
        return new_root;
    }

    if (root) {
        root->left = addOneRow(root->left, v, d - 1 == 1 ? 1 : d - 1);
        root->right = addOneRow(root->right, v, d - 1 == 1 ? 0 : d - 1);
    }

    return root;
}
```
