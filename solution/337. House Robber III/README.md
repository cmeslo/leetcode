# 337. House Robber III

version 1

```cpp
class Solution {
public:
    unordered_map<TreeNode*, int> robMap, passMap;

    int rob(TreeNode* root) {
        robMap.clear(), passMap.clear();

        return max(robRoot(root), passRoot(root));
    }

    int robRoot(TreeNode* root)
    {
        if (!root) return 0;
        if (robMap.count(root)) return robMap[root];

        robMap[root] = root->val + passRoot(root->left) + passRoot(root->right);

        return robMap[root];
    }

    int passRoot(TreeNode* root)
    {
        if (!root) return 0;
        if (passMap.count(root)) return passMap[root];

        passMap[root] =
            max(robRoot(root->left), passRoot(root->left)) +
            max(robRoot(root->right), passRoot(root->right));

        return passMap[root];
    }
};
```

version 2

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        return max(rob(root, true), rob(root, false));
    }
    
private:
    unordered_map<TreeNode*, int> robRoot, passRoot;
    
    int rob(TreeNode* root, bool rootIncluded) {
        if (!root) return 0;
        if (rootIncluded && robRoot.count(root)) return robRoot[root];
        if (!rootIncluded && passRoot.count(root)) return passRoot[root];
        
        int left = rob(root->left, false);
        int right = rob(root->right, false);
        
        if (!rootIncluded) {
            left = max(left, rob(root->left, true));
            right = max(right, rob(root->right, true));
        }
        
        if (rootIncluded) {
            return robRoot[root] = root->val + left + right;
        } else {
            return passRoot[root] = left + right;
        }
    }
};
```

version 3

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = helper(root);
        return max(ans[0], ans[1]);
    }
    
private:
    vector<int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        
        vector<int> ans(2);
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = root->val + left[0] + right[0];
        return ans;
    }
};
```
