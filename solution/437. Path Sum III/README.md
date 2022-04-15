# 437. Path Sum III

## Solution 1: DFS + Brute force (437_01.cpp)

```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        
        return pathSum(root->left, sum)
            + pathSum(root->right, sum)
            + pathSumWithRoot(root, sum);
    }

private:
    int pathSumWithRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        
        return (root->val == sum ? 1 : 0)
            + pathSumWithRoot(root->left, sum - root->val)
            + pathSumWithRoot(root->right, sum - root->val);
    }
};
```

## Solution 2: DFS + Prefix Sum (437_02.cpp)

```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        _ans = 0;
        _prefixSum = {{0, 1}};
        
        pathSum(root, 0, sum);
        return _ans;
    }

private:
    int _ans;
    unordered_map<int, int> _prefixSum;
    
    void pathSum(TreeNode* node, int cur, int sum) {
        if (!node) return;
        
        cur += node->val;
        _ans += _prefixSum[cur - sum];
        
        _prefixSum[cur]++;
        pathSum(node->left, cur, sum);
        pathSum(node->right, cur, sum);
        _prefixSum[cur]--;
    }
};
```
