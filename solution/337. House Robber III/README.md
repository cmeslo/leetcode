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
    
    int rob(TreeNode* root, bool isRob) {
        if (!root) return 0;
        
        if (isRob) {
            if (dpRob.count(root)) return dpRob[root];
            return dpRob[root] = root->val + rob(root->left, false) + rob(root->right, false);
        } else {
            if (dpPass.count(root)) return dpPass[root];
            return dpPass[root] = max(rob(root->left, true), rob(root->left, false))
                + max(rob(root->right, true), rob(root->right, false));
        }
    }
    
private:
    unordered_map<TreeNode*, int> dpRob;
    unordered_map<TreeNode*, int> dpPass;
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
