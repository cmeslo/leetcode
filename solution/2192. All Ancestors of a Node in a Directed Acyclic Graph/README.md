# 2192. All Ancestors of a Node in a Directed Acyclic Graph

## Solution 1: Topological sort + bitset

```cpp
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n);
    vector<vector<int>> G(n);
    for (auto& e : edges) {
        int a = e[0], b = e[1];
        G[a].push_back(b);
        inDegree[b]++;
    }

    vector<bitset<1001>> ans(n);

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int node = q.front(); q.pop();
            for (int next : G[node]) {
                ans[next] |= ans[node];
                ans[next].set(node);
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
    }

    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j])
                res[i].push_back(j);
        }
        // cout << ans[i].count() << endl;
    }
    return res;
}
```

## Solution 2: DFS

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            adj[to].push_back(from);
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(i, adj, visited, ans[i]);
            ans[i].pop_back();
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
    
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        if (visited[i]) return;
        
        visited[i] = true;
        for (int a : adj[i]) {
            dfs(a, adj, visited, ans);
        }
        ans.push_back(i);
    }
};
```
