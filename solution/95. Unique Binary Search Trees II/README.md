# 95. Unique Binary Search Trees II

## Solution: Recursion

```cpp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
private:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr};
        
        vector<TreeNode*> ans;
        for (int i = start; i <= end; ++i) {
            auto left_subtrees = generateTrees(start, i - 1);
            auto right_subtrees = generateTrees(i + 1, end);
            for (auto l : left_subtrees) {
                for (auto r : right_subtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
```
