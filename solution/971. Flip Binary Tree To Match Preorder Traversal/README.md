# 971. Flip Binary Tree To Match Preorder Traversal

## Solution 1 - DFS

```cpp
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int i = 0;
        return dfs(root, voyage, i, ans) ? ans : vector<int> {-1};
    }
    
private:
    bool dfs(TreeNode* node, vector<int>& v, int& i, vector<int>& ans) {
        if (!node) return true;
        if (node->val != v[i++]) return false;
        
        if (node->left && node->left->val != v[i]) {
            ans.push_back(node->val);
            return dfs(node->right, v, i, ans) && dfs(node->left, v, i, ans);
        }
        return dfs(node->left, v, i, ans) && dfs(node->right, v, i, ans);
    }
};
```

## Solution 2 - BFS

```cpp
vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> ans;

    stack<TreeNode*> st;
    st.push(root);
    int i = 0;
    while (!st.empty()) {
        auto node = st.top(); st.pop();
        if (node->val != voyage[i++]) return {-1};
        if (node->left && node->left->val != voyage[i]) {
            ans.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        } else {
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
    }
    return ans;
}
```
