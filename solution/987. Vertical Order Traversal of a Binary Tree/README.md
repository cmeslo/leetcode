# 987. Vertical Order Traversal of a Binary Tree

## 987_01.cpp

DFS, map and priority_queue

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

DFS, map and sort.

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<PII>> m;
        dfs(root, 0, 0, m);
        
        vector<vector<int>> ans;
        for (auto& [x, list] : m) {
            sort(begin(list), end(list));
            vector<int> tmp;
            for (auto [level, val] : list)
                tmp.push_back(val);
            ans.push_back(tmp);
        }
        return ans;
    }
    
private:
    using PII = pair<int, int>; // {level, value}
    
    void dfs(TreeNode* node, int level, int x, map<int, vector<PII>>& m) {
        if (!node) return;
        m[x].push_back({level, node->val});
        dfs(node->left, level + 1, x - 1, m);
        dfs(node->right, level + 1, x + 1, m);
    }
};
```

## 987_03.cpp

BFS, map and sort.

```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    map<int, vector<pair<int, int>>> m; // x -> [{y1, val1}, {y2, val2}]
    queue<pair<int, TreeNode*>> q;
    q.push({0, root});
    int y = 0;
    int x_min = 0, x_max = 0;

    while (!q.empty()) {
        int size = q.size();
        ++y;
        while (size--) {
            auto [x, node] = q.front(); q.pop();
            m[x].push_back({y, node->val});
            x_min = min(x_min, x);
            x_max = max(x_max, x);
            if (node->left) q.push({x - 1, node->left});
            if (node->right) q.push({x + 1, node->right});
        }
    }

    vector<vector<int>> ans;
    for (int i = x_min; i <= x_max; ++i) {
        vector<int> cur;
        sort(begin(m[i]), end(m[i]), [&](auto& a, auto& b) {
            return (a.first < b.first) || (a.first == b.first && a.second < b.second);
        });
        for (const auto& [x, val] : m[i])
            cur.push_back(val);
        ans.push_back(cur);
    }
    return ans;
}
```

or

```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        map<int, multiset<int>> tmp;
        for (int size = q.size(); size > 0; --size) {
            auto [node, x] = q.front(); q.pop();
            tmp[x].insert(node->val);
            if (node->left)
                q.push({node->left, x - 1});
            if (node->right)
                q.push({node->right, x + 1});
        }
        for (auto [x, arr] : tmp) {
            for (int val : arr)
                m[x].push_back(val);
        }
    }

    vector<vector<int>> res;
    for (auto& [k, v] : m)
        res.push_back(v);
    return res;
}
```
