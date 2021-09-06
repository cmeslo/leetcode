# 105. Construct Binary Tree from Preorder and Inorder Traversal

## Solution: Recursion

### 解釋

用 Preorder 的根節點，可以把 Inorder 分成左右子樹，再遞歸處理。

```
preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

  3
 / \
9  20
   /\
  15 7
```

### Code

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            pos_[inorder[i]] = i;
        int i = 0;
        return dfs(preorder, i, inorder, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> pos_;
    
    TreeNode* dfs(vector<int>& preorder, int& i, vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;
        
        int val = preorder[i++];
        auto root = new TreeNode(val);
        int m = pos_[val];
        root->left = dfs(preorder, i, inorder, l, m - 1);
        root->right = dfs(preorder, i, inorder, m + 1, r);
        return root;
    }
};
```
