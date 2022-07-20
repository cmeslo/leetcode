# 1026. Maximum Difference Between Node and Ancestor



## Solution: DFS

### 寫法一：自下而上

```cpp
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (!root) return {INT_MIN, INT_MAX};
        
        // pair<max, min>
        pair<int, int> left = dfs(root->left, ans);
        pair<int, int> right = dfs(root->right, ans);
        
        if (left.first != INT_MIN)
            ans = max(ans, abs(root->val - left.first));
        if (right.first != INT_MIN)
            ans = max(ans, abs(root->val - right.first));
        if (left.second != INT_MAX)
            ans = max(ans, abs(root->val - left.second));
        if (right.second != INT_MAX)
            ans = max(ans, abs(root->val - right.second));
        
        int maxVal = max({root->val, left.first, right.first});
        int minVal = min({root->val, left.second, right.second});
        return {maxVal, minVal};
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
