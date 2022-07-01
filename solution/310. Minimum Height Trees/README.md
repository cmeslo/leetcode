# 310. Minimum Height Trees



## Solution: Topological sort (310_01.cpp)

### 解釋

從邊緣（葉子）開始往中心消除，到剩下 1 或 2 個節點時就是 <strong>最小樹高</strong> 的樹根。

### Code

```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> inDegree(n);
    for (auto& e : edges) {
        int a = e[0], b = e[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++inDegree[a];
        ++inDegree[b];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (inDegree[i] <= 1)
            q.push(i);

    int count = n;
    while (count > 2) {
        count -= q.size();
        for (int i = q.size(); i > 0; --i) {
            int node = q.front(); q.pop();
            --inDegree[node];
            for (int next : adj[node]) {
                if (inDegree[next] == 0) continue;
                if (--inDegree[next] == 1) {
                    q.push(next);
                }
            }
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
```

### 寫法二 (310_02.cpp)

```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n < 2) return {0};

    vector<unordered_set<int>> g(n);
    for (const auto& edge : edges) {
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }

    queue<int> leaves;
    for (int i = 0; i < n; ++i)
        if (g[i].size() == 1)
            leaves.push(i);

    while (n > 2) {
        int size = leaves.size();
        n -= size;

        for (int i = 0; i < size; ++i) {
            int leaf = leaves.front(); leaves.pop();
            int next = *g[leaf].begin();
            g[next].erase(leaf);
            if (g[next].size() == 1) leaves.push(next);
        }
    }

    vector<int> res;
    while (!leaves.empty()) {
        res.push_back(leaves.front());
        leaves.pop();
    }
    return res;
}
