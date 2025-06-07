# 2196. Create Binary Tree From Descriptions

## Solution 1: DFS

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> leaf;
        unordered_map<int, pair<int, int>> m;
        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (isLeft)
                m[parent].first = child;
            else
                m[parent].second = child;
            leaf.insert(child);
        }
        
        // find root;
        int rootVal = 0;
        for (auto& d : descriptions) {
            if (!leaf.count(d[0])) {
                rootVal = d[0];
                break;
            }
        }
        
        TreeNode* root = new TreeNode(rootVal);
        dfs(root, m);
        return root;
    }
    
    void dfs(TreeNode* node, unordered_map<int, pair<int, int>>& m) {
        if (!m.count(node->val)) return;
        
        if (m[node->val].first) {
            node->left = new TreeNode(m[node->val].first);
            dfs(node->left, m);
        }
        if (m[node->val].second) {
            node->right = new TreeNode(m[node->val].second);
            dfs(node->right, m);
        }
    }
};
```
