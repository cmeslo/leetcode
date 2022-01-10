# 1339. Maximum Product of Splitted Binary Tree

## Solution 1: DFS + Memorize

```cpp
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const int M = 1e9 + 7;
        dfs(root, 0);
        return ans_ % M;
    }
    
private:
    long ans_ = 0;
    
    unordered_map<TreeNode*, long> memo_;
    long get_sum(TreeNode* node) {
        if (!node) return 0;
        if (memo_.count(node)) return memo_[node];
        return memo_[node] = node->val + get_sum(node->left) + get_sum(node->right);
    }
    
    void dfs(TreeNode* node, long parent_sum) {
        if (!node) return;
        
        long cur_sum = parent_sum + node->val;
        long l = get_sum(node->left);
        long r = get_sum(node->right);
        
        ans_ = max(ans_, l * (cur_sum + r)); // split left
        ans_ = max(ans_, r * (cur_sum + l)); // split right
        
        dfs(node->left, cur_sum + r);
        dfs(node->right, cur_sum + l);
    }
};
```

## Solution 2: DFS + Two pass (推薦)

```cpp
class Solution {
public:
    int maxProduct(TreeNode* root) {
        total_ = s(root);
        s(root);
        return ans_ % (int)(1e9 + 7);
    }
    
private:
    long ans_ = 0, total_ = 0;
    
    long s(TreeNode* node) {
        if (!node) return 0;
        long sub = node->val + s(node->left) + s(node->right);
        ans_ = max(ans_, sub * (total_ - sub));
        return sub;
    }
};
```
