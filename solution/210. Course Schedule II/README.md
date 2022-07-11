# 210. Course Schedule II

## Solution 1: Topological Sort

```cpp
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> inDegree(n);
    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> res;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        res.push_back(node);
        for (int next : adj[node]) {
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 0; i < n; ++i)
        if (inDegree[i] != 0)
            return {};

    return res;
}
```

## Solution 2: DFS

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = vector<vector<int>>(numCourses);
        vector<int> v = vector<int>(numCourses, 0); // 0 = unknow, 1 = visiting, 2 = visited
        
        for (const auto& pre : prerequisites)
            g[pre[1]].push_back(pre[0]);
        
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, ans, g, v)) return {};
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    // topologic sort
    bool dfs(int node, vector<int>& ans, vector<vector<int>>& g, vector<int>& v) {
        if (v[node] == 1) return true; // cycle
        if (v[node] == 2) return false;
        
        v[node] = 1;
        for (int neighbour : g[node]) {
            if (dfs(neighbour, ans, g, v)) return true;
        }
        v[node] = 2;
        ans.push_back(node);
        
        return false;
    }
};
```
