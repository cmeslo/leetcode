# 653. Two Sum IV - Input is a BST

## Solution 1: DFS

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (pre.count(k - root->val))
            return true;
        pre.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
private:
    unordered_set<int> pre;
};
```
