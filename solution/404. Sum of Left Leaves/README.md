## Solution 1: DFS

### 404_01.cpp

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
    
private:
    int dfs(TreeNode* root, bool isLeft) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) return root->val;
        
        return dfs(root->left, true) + dfs(root->right, false);
    }
};
```

### 404_02.cpp

```cpp
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    if (root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);

    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
```

## Solution 2: Stack

### 404_03.cpp

```cpp
int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;

    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        auto cur = st.top(); st.pop();
        if (cur->left) {
            while (cur && cur->left) {
                if (cur->right)
                    st.push(cur->right);
                cur = cur->left;
            }
            if (!cur->right)
                res += cur->val;
        }
        if (cur->right)
            st.push(cur->right);
    }

    return res;
}
```
