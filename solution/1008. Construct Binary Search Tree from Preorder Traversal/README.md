# 1008. Construct Binary Search Tree from Preorder Traversal

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
