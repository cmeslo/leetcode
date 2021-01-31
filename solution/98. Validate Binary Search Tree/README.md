# 98. Validate Binary Search Tree

## 98_01.cpp

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

## 98_02.cpp

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
