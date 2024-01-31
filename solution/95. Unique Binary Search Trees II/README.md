# 95. Unique Binary Search Trees II

## Solution: Recursion

### C++
```cpp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) return { nullptr };

        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> L = dfs(start, i - 1);
            vector<TreeNode*> R = dfs(i + 1, end);
            for (auto& l : L) {
                for (auto& r : R) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
```

### Python

```py
def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
    def dfs(start, end):
        if start > end:
            return [None]
        res = []
        for i in range(start, end + 1):
            L = dfs(start, i - 1)
            R = dfs(i + 1, end)
            for l in L:
                for r in R:
                    root = TreeNode(i, l, r)
                    res.append(root)
        return res
    
    return dfs(1, n)
```
