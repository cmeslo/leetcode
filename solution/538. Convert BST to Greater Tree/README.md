# 538. Convert BST to Greater Tree

## 解釋

一直追蹤着當前遍歷到的累加數和 sum，再把這個 sum 加到自己節點的值上。

```cpp
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    
private:
    void dfs(TreeNode* node, int& sum) {
        if (!node) return;
        
        dfs(node->right, sum);
        sum = node->val += sum;
        dfs(node->left, sum);
    }
};
```
