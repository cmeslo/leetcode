# 102. Binary Tree Level Order Traversal

## Solution: BFS

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> cur;
        for (int i = q.size() - 1; i >= 0; --i) {
            auto node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            cur.push_back(node->val);
        }
        ans.push_back(cur);
    }
    return ans;
}
```
