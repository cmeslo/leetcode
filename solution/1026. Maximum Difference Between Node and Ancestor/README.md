# 1026. Maximum Difference Between Node and Ancestor



## Solution: DFS

### 寫法一：自下而上

```cpp
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* node, int& res) {
        if (!node) return {-1, -1};
        auto [l_min, l_max] = dfs(node->left, res);
        auto [r_min, r_max] = dfs(node->right, res);
        int  mn = node->val, mx = node->val;
        if (l_min != -1) {
            res = max(res, abs(node->val - l_min));
            res = max(res, abs(node->val - l_max));
            mn = min(mn, l_min);
            mx = max(mx, l_max);
        }
        if (r_min != -1) {
            res = max(res, abs(node->val - r_min));
            res = max(res, abs(node->val - r_max));
            mn = min(mn, r_min);
            mx = max(mx, r_max);
        }
        return {mn, mx};
    }
};
```

### 寫法二：自上而下 (推薦)

```cpp
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    
private:
    int dfs(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(dfs(node->left, mn, mx),
                   dfs(node->right, mn, mx));
    }
};
```
