# 1457. Pseudo-Palindromic Paths in a Binary Tree

由於只考慮從 root 到 leaf 的路徑，然後又可以重新排序，

所以只要記錄當前遍歷時 1~9 的狀態就可以了，每遇到一個數字就toggle，

最後如果剩下 0 個或 1 個數字，就代表找到一條 path。

## 方法一，用數組記錄 1 - 9

```cpp
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10);
        return dfs(root, f);
    }
    
private:
    int dfs(TreeNode* root, vector<int>& f) {
        if (!root) return 0;
        
        int ans = 0;
        f[root->val] = 1 - f[root->val];
        if (!root->left && !root->right) {
            int sum = accumulate(begin(f), end(f), 0);
            ans = sum == 0 || sum == 1;
        } else {
            ans = dfs(root->left, f) + dfs(root->right, f);
        }
        f[root->val] = 1 - f[root->val];
        
        return ans;
    }
};
```

## 方法二，用一個 int 記錄 1 - 9

```cpp
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* root, int f) {
        if (!root) return 0;
        
        int ans = 0;
        
        f ^= 1 << (root->val - 1);
        if (!root->left && !root->right)
            ans = (f & (f - 1)) == 0;
        else
            ans = dfs(root->left, f) + dfs(root->right, f);
        
        return ans;
    }
};
```
