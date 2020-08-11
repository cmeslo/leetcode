# 987. Vertical Order Traversal of a Binary Tree

## 987_01.cpp

dfs, map and priority_queue

Time complexity: O(nlogn)

```map <X, priority_queue<pair<Y, val>>>```

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int, priority_queue<pair<int, int>>> m;
        dfs(m, root, 0, 0);
        
        for (int i = min_l; i <= max_r; i++) {
            if (m.find(i) == m.end()) continue;
            vector<int> cur(m[i].size());
            for (int j = m[i].size() - 1; j >= 0; j--) {
                cur[j] = m[i].top().second; m[i].pop();
            }
            ans.push_back(cur);
        }
        
        return ans;
    }
    
private:
    int min_l, max_r;
    
    void dfs(unordered_map<int, priority_queue<pair<int, int>>>& m, TreeNode* node, int y, int x) {
        if (!node) return;
        
        m[x].push({y, node->val});
        min_l = min(min_l, x);
        max_r = max(max_r, x);
        
        if (node->left) dfs(m, node->left, y+1 ,x-1);
        if (node->right) dfs(m, node->right, y+1 ,x+1);
    }
};
```

## 987_02.cpp

dfs, map and sort

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> m;
        dfs(m, root, 0, 0);
        
        for (int i = min_l; i < max_r + 1; i++) {
            sort(m[i].begin(), m[i].end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
                return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
            });
            vector<int> cur;
            for (const auto& p : m[i])
                cur.push_back(p.second);
            ans.push_back(cur);
        }
        
        return ans;
    }
    
private:
    int min_l, max_r;
    
    void dfs(map<int, vector<pair<int, int>>>& m, TreeNode* node, int y, int x) {
        if (!node) return;
        
        m[x].push_back({y, node->val});
        
        min_l = min(min_l, x);
        max_r = max(max_r, x);
        
        dfs(m, node->left, y+1, x-1);
        dfs(m, node->right, y+1, x+1);
    }
};
```
