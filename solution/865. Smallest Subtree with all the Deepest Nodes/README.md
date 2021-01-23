# 865. Smallest Subtree with all the Deepest Nodes

## Recursive

### 865_01.cpp

```cpp
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left.second == right.second)
            return {root, left.second + 1};
        
        auto& ans = left.second > right.second ? left : right;
        return {ans.first, ans.second + 1};
    }
};
```

or

### 865_02.cpp

```cpp
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans;
        depth(root, &ans);
        return ans;
    }

private:
    int depth(TreeNode* root, TreeNode** ans) {
        if (!root) return 0;
        
        TreeNode *pl, *pr;
        int left = depth(root->left, &pl);
        int right = depth(root->right, &pr);
        
        *ans = left == right ? root : left > right ? pl : pr;
        return 1 + max(left, right);
    }
};
```
