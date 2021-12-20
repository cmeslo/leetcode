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

## Solution 2: DFS

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        return ans;
    }
    
private:
    void preorder(Node* root, int depth, vector<vector<int>>& ans) {
        if (!root) return;
        while (ans.size() <= depth) ans.push_back({});
        ans[depth].push_back(root->val);
        for (auto* child : root->children)
            preorder(child, depth+1, ans);
    }
};
```
