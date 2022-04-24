# 222. Count Complete Tree Nodes

## Solution 1: Brute force DFS

```cpp
int countNodes(TreeNode* root) {
    return root? 1 + countNodes(root->left) + countNodes(root->right) : 0;
}
```

## Solution 2: Binary search + 利用 Complete Tree 的性質驗證

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = 0;
        auto p = root;
        while (p) {
            ++h;
            p = p->left;
        }
        
        int low = 1 << (h-1);
        int high = (1 << h) - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (hasK(root, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
    
    bool hasK(TreeNode* root, int k) {
        vector<int> path;
        while (k) {
            path.push_back(k);
            k /= 2;
        }
        
        for (int i = path.size() - 1; i >= 0; --i) {
            if (!root) return false;
            if (i > 0) {
                if (path[i] * 2 == path[i - 1])
                    root = root->left;
                else
                    root = root->right;
            }
        }
        return true;
    }
};
```

## Solution 3: DFS + Pruning

如果左右長度一樣就可以剪掉 (也是利用了 Complete Tree 的性質)

```cpp
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int left_h = 0, right_h = 0;
    auto p1 = root, p2 = root;
    while (p1) {
        ++left_h;
        p1 = p1->left;
    }
    while (p2) {
        ++right_h;
        p2 = p2->right;
    }

    if (left_h == right_h)
        return (1 << left_h) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```
