# 847. Shortest Path Visiting All Nodes

## Solution: BFS + Bitmask

```cpp
// Runtime: 12 ms, Your runtime beats 99.04 % of cpp submissions.
// Memory Usage: 9 MB, Your memory usage beats 90.03 % of cpp submissions.

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<bool>> visited(n, vector<bool>(1 << n)); // {node, state};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int state = 1 << i;
        visited[i][state] = true;
        q.push({i, state});
    }

    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [node, state] = q.front(); q.pop();
            for (int next : graph[node]) {
                int nextState = state | (1 << next);
                if (nextState == (1 << n) - 1)
                    return step + 1;
                if (visited[next][nextState])
                    continue;
                visited[next][nextState] = true;
                q.push({next, nextState});
            }
        }
        step++;
    }
    return 0;
}
```
