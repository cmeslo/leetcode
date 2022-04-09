# 1008. Construct Binary Search Tree from Preorder Traversal

## Solution: DFS

### 寫法一

```cpp
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        return dfs(preorder, 0, n - 1);
    }
    
private:
    int n;
    TreeNode* dfs(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        
        auto node = new TreeNode(preorder[start]);
        int i = start;
        while (i+1 <= end && preorder[i+1] < preorder[start]) ++i;
        node->left = dfs(preorder, start + 1, i);
        node->right = dfs(preorder, i + 1, end);
        return node;
    }
};
```

### 寫法二

```cpp
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
    
private:
    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;
        auto node = new TreeNode(A[i++]);
        node->left = build(A, i, node->val);
        node->right = build(A, i, bound);
        return node;
    }
};
```
