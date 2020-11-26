# 99. Recover Binary Search Tree

## 99_01.cpp

recursive

Your runtime beats 98.59 % of cpp submissions.

```cpp
class Solution {
public:
    void recoverTree(TreeNode* root) {
        pre = nullptr, first = nullptr, second = nullptr;
        inOrderTraversal(root);
        swap(first->val, second->val);
    }
    
private:
    TreeNode *pre, *first, *second;
    
    void inOrderTraversal(TreeNode* root) {
        if (!root) return;
        if (root->left) inOrderTraversal(root->left);
        
        if (!pre) {
            pre = root;
        } else {
            if (pre->val > root->val) {
                if (!first) first = pre;
                second = root;
            }
        }
        pre = root;
        
        if (root->right) inOrderTraversal(root->right);
    }
};
```

## 99_02.cpp

```cpp
void recoverTree(TreeNode* root) {
    TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;

    TreeNode *cur = root;
    while (cur) {
        if (!cur->left) {
            // cout << cur->val << ", ";
            if (pre && pre->val > cur->val) {
                if (!first) first = pre;
                second = cur;
            }
            pre = cur;

            cur = cur->right;
        } else {
            auto *tmp = cur->left;
            while (tmp->right && tmp->right != cur)
                tmp = tmp->right;
            if (!tmp->right) {
                tmp->right = cur;
                cur = cur->left;
            } else { // left child finished
                tmp->right = nullptr;
                // cout << cur->val << ", ";
                if (pre && pre->val > cur->val) {
                    if (!first) first = pre;
                    second = cur;
                }
                pre = cur;

                cur = cur->right;
            }
        }
    }
    swap(first->val, second->val);
}
```

or

```cpp
void recoverTree(TreeNode* root) {
    TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;

    TreeNode *cur = root;
    while (cur) {
        if (cur->left) {
            auto *tmp = cur->left;
            while (tmp->right && tmp->right != cur)
                tmp = tmp->right;
            if (!tmp->right) {
                tmp->right = cur;
                cur = cur->left;
                continue;
            } else { // left child finished
                tmp->right = nullptr;
            }
        }
        // cout << cur->val << ", ";
        if (pre && pre->val > cur->val) {
            if (!first) first = pre;
            second = cur;
        }
        pre = cur;

        cur = cur->right;
    }
    swap(first->val, second->val);
}
```
