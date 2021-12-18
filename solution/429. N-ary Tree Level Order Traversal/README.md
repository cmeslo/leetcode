# 429. N-ary Tree Level Order Traversal

## Solution 1: BFS

```cpp
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        vector<int> cur;
        for (int size = q.size(); size > 0; --size) {
            auto node = q.front(); q.pop();
            cur.push_back(node->val);
            for (auto child : node->children)
                q.push(child);
        }
        ans.push_back(cur);
    }
    return ans;
}
```
