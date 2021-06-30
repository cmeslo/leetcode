# 1302. Deepest Leaves Sum

## Solution 1: DFS

```cpp
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int depth_max = 1;
        dfs(root, 1, depth_max, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, int depth, int& depth_max, int& ans) {
        if (!node) return;
        
        if (depth > depth_max) {
            depth_max = depth;
            ans = node->val;
        } else if (depth == depth_max) {
            ans += node->val;
        }
        
        dfs(node->left, depth + 1, depth_max, ans);
        dfs(node->right, depth + 1, depth_max, ans);
    }
};
```

## Solution 2: BFS

```cpp
int deepestLeavesSum(TreeNode* root) {
    int ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        ans = 0;
        for (int i = q.size() - 1; i >= 0; --i) {
            auto node = q.front(); q.pop();
            ans += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}
```
