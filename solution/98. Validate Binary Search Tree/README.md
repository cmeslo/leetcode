# 98. Validate Binary Search Tree

## Solution 1: DFS (98_01.cpp)

```cpp
bool isValidBST(TreeNode* root) {
    if (!root) return true;

    if (root->left) {
        auto p = root->left;
        while (p->right)
            p = p->right;
        if (!(p->val < root->val))
            return false;
    }
    if (root->right) {
        auto p = root->right;
        while (p->left)
            p = p->left;
        if (!(root->val < p->val))
            return false;
    }
    return isValidBST(root->left) && isValidBST(root->right);
}
```

## Solution 2: DFS

(98_02.cpp)

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    
private:
    bool dfs(TreeNode* root, TreeNode* upper_bound, TreeNode* lower_bound) {
        if (!root) return true;
        
        if (upper_bound && !(root->val < upper_bound->val)) return false;
        if (lower_bound && !(lower_bound->val < root->val)) return false;
        
        return dfs(root->left, root, lower_bound)
            && dfs(root->right, upper_bound, root);
    }
};
```

or

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool dfs(TreeNode* node, long mn, long mx) {
        if (!node) return true;
        
        return mn < node->val &&
               node->val < mx &&
               dfs(node->left, mn, node->val) &&
               dfs(node->right, node->val, mx);
    }
};
```
