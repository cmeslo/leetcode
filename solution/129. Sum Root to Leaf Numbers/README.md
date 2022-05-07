# 129. Sum Root to Leaf Numbers

## Solution: DFS

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur) {
        if (!root) return 0;
        cur = cur * 10 + root->val;
        if (!root->left && !root->right)
            return cur;
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};
```

## Solution: Stack

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
