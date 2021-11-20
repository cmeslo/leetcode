# 235. Lowest Common Ancestor of a Binary Search Tree

## Solution 1

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (p->val < root->val && q->val < root->val) 
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}
```