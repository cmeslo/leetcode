# 1372. Longest ZigZag Path in a Binary Tree

## Solution: DFS

```cpp
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return res;
    }
    
private:
    int res = 0;
    
    void dfs(TreeNode* root, int left, int right) {
        if (!root) {
            res = max({res, left - 1, right - 1});
            return;
        }
        
        dfs(root->left, 0, left + 1);
        dfs(root->right, right + 1, 0);
    }
};
```

or

```cpp
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        return dfs(root, 0, 0);
    }
    
private:
    int dfs(TreeNode* root, int left, int right) {
        if (!root) return max(left - 1, right - 1);
        
        return max(dfs(root->left, 0, left + 1),
                   dfs(root->right, right + 1, 0));
    }
};
```
