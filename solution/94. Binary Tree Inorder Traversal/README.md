# 94. Binary Tree Inorder Traversal

## Solution 1

```cpp
vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    stack<TreeNode*> st;

    auto* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top(); st.pop();
        ans.push_back(cur->val);
        cur = cur->right;
    }
    return ans;
}
```

## Solution 2

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }
    
private:
    void inorderTraversal(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        inorderTraversal(node->left, ans);
        ans.push_back(node->val);
        inorderTraversal(node->right, ans);
    }
};
```
