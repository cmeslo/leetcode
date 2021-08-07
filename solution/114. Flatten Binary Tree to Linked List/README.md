# 114. Flatten Binary Tree to Linked List

## Solution 1: Recursive

### 寫法一（容易寫，但不夠好）：

```cpp
void flatten(TreeNode* root) {
    if (!root) return;

    auto l = root->left;
    auto r = root->right;
    flatten(l);
    root->left = nullptr;
    if (l) {
        root->right = l;
        while (l && l->right) // <----為了找到尾巴，要重複走一次
            l = l->right;
        l->right = r;
    }
    flatten(r);
}
```

### 寫法二（推薦，但有點難想到）：

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
    
private:
    TreeNode* pre = nullptr;
};
```

## Solution 2: Iterative（推薦）

Solution 1 由於遞歸用了 stack，所以 space complexity 不是 O(1) 的，

Solution 2 是迭代的寫法，比 Solution 1 的寫法二更簡單，類似 Morris traversal。

```cpp
void flatten(TreeNode* root) {
    auto cur = root;
    while (cur) {
        if (cur->left) {
            auto p = cur->left;
            while (p->right)
                p = p->right;
            p->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}
```

reference:
- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
