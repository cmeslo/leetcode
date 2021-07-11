# 589. N-ary Tree Preorder Traversal

## Solution 1: Stack

```cpp
vector<int> preorder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        auto node = st.top(); st.pop();
        ans.push_back(node->val);
        for (int i = node->children.size() - 1; i >= 0; --i)
            st.push(node->children[i]);
    }
    return ans;
}
```

## Solution 2: DFS

```cpp
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(Node* node, vector<int>& ans) {
        if (!node) return;
        ans.push_back(node->val);
        for (auto child : node->children)
            dfs(child, ans);
    }
};
```
