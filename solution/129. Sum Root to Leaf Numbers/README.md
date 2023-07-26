# 129. Sum Root to Leaf Numbers

## Solution 1: DFS

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
	int dfs(TreeNode* node, int num) {
		if (!node) return 0;
        
		num = num * 10 + node->val;
		if (!node->left && !node->right)
			return num;
        
		return dfs(node->left, num) + dfs(node->right, num);
	}
};
```

## Solution 2: Stack 實現 DFS

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
