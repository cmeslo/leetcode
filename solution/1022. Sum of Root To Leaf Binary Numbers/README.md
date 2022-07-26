# 1022. Sum of Root To Leaf Binary Numbers

## Solution: DFS

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(TreeNode* node, int cur, int& res) {
        if (!node) {
            return;
        }
        cur <<= 1;
        cur |= node->val;
        if (!node->left && !node->right) {
            res += cur;
            return;
        }
        dfs(node->left, cur, res);
        dfs(node->right, cur, res);
    }
};
```

or

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum * 2 + root->val;
        if (!root->left && !root->right)
            return sum;
        else
            return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
```