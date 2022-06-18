# 337. House Robber III

## Solution 1

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

or

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

## Solution 2 (推薦)

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        auto ans = dp(root);
        return max(ans.first, ans.second);
    }
    
private:
    pair<int, int> dp(TreeNode* node) { // rob node, pass node
        if (!node) return {0, 0};
        
        auto l = dp(node->left);
        auto r = dp(node->right);
        
        return {node->val + l.second + r.second,
                max(l.first, l.second) + max(r.first, r.second)};
    }
};
```
