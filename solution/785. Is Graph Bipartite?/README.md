# 785. Is Graph Bipartite?

## Solution 1: DFS

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n); // 0: unknow, 1: red, -1: blue
        for (int i = 0; i < n; ++i)
            if (colors[i] == 0 && !dfs(graph, i, 1, colors))
                return false;
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& g, int i, int color, vector<int>& colors) {
        if (colors[i] != 0) return colors[i] == color;
        
        colors[i] = color;
        for (int next : g[i])
            if (!dfs(g, next, -color, colors))
                return false;
        
        return true;
    }
};
```

## Solution 2: BFS

```cpp
// Your runtime beats 98.28 % of cpp submissions.
// Your memory usage beats 96.24 % of cpp submissions.

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n); // 0: unknow, 1: red, -1: blue
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (colors[i] != 0) continue;
        colors[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int next : graph[cur]) {
                if (colors[next] == colors[cur]) return false;
                if (colors[next] != 0) continue;
                colors[next] = -colors[cur];
                q.push(next);
            }
        }
    }
    return true;
}
```
