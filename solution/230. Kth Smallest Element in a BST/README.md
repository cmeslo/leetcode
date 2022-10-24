# 230. Kth Smallest Element in a BST

## Solution 1

```cpp
int kthSmallest(TreeNode* root, int k) {
    auto p = root;
    stack<TreeNode*> st;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }

        p = st.top(); st.pop();
        if (--k == 0) return p->val;

        p = p->right;
    }
    return -1;
}
```

## Solution 2: DFS

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }
    
private:
    int k;
    int ans = -1;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        
        dfs(root->left);
        
        if (--k == 0) {
            ans = root->val;
            return;
        }
        
        dfs(root->right);
    }
};
```
