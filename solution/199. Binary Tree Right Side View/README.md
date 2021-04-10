# 199. Binary Tree Right Side View

## Solution 1: BFS

```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    deque<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()) {
        ans.push_back(q.back()->val);
        int size = q.size();
        while (size--) {
            auto node = q.front(); q.pop_front();
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
    }
    return ans;
}
```

or

```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (i == size - 1) ans.push_back(node->val);
        }
    }
    return ans;
}
```
