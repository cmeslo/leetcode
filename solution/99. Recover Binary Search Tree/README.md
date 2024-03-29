# 99. Recover Binary Search Tree

## Solution 1: DFS (99_01.cpp)

Your runtime beats 98.59 % of cpp submissions.

```cpp
class Solution {
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
    
private:
    TreeNode *pre, *first, *second;
    
    void dfs(TreeNode* node) {
        if (!node) return;
        
        dfs(node->left);
        
        if (pre && pre->val > node->val) {
            if (!first) first = pre;
            second = node;
        }
        pre = node;
        
        dfs(node->right);
    }
};
```

## Solution 2: morris traversal (99_02.cpp)

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

## Solution 3: inorder traversal with stack (99_03.cpp)

```cpp
void recoverTree(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;
    auto p = root;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        p = st.top(); st.pop();
        if (pre && pre->val > p->val) {
            if (!first) first = pre;
            second = p;
        }
        pre = p;
        p = p->right;
    }
    swap(first->val, second->val);
}
```
