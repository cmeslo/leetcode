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
