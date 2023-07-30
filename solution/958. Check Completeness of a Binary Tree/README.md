# 958. Check Completeness of a Binary Tree

## Solution 3: BFS

出現第一個空節點後, 不能再見到非空節點

```cpp
bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool seenEmpty = false;
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        if (!node) {
            seenEmpty = true;
        } else {
            if (seenEmpty) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}
```
