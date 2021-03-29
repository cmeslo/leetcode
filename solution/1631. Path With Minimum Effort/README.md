# 1631. Path With Minimum Effort

## Solution 1: binary search 猜答案 + BFS/DFS 驗證

找到一條能夠走通的 lower bound 通路，每次用 bfs/dfs 看能否走通，

這個方法可以 AC，但 runtime 不是太好。

```cpp
int minimumEffortPath(vector<vector<int>>& H) {
    int h = H.size(), w = H[0].size();
    vector<int> dirs = {0, -1, 0, 1, 0};
    auto bfs = [&](int cost) -> bool {
        queue<pair<int, int>> q;
        vector<int> seen(h * w);
        q.emplace(0, 0);
        seen[0] = 1;
        while (!q.empty()) {
            auto [cy, cx] = q.front(); q.pop();
            if (cy == h - 1 && cx == w - 1) return true;
            for (int i = 0; i < 4; ++i) {
                int y = cy + dirs[i];
                int x = cx + dirs[i + 1];
                if (y < 0 || y >= h || x < 0 || x >= w) continue;
                if (abs(H[cy][cx] - H[y][x]) > cost) continue;
                if (seen[y * w + x]) continue;
                seen[y * w + x] = 1;
                q.emplace(y, x);
            }
        }
        return false;
    };

    int l = 0, r = 1e6 + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (bfs(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
```

## Solution 2: Dijkstra's algorithm

### 1. 只要把 Dijkstra 算法的計算路徑和

```py
dist[v] = dist[u] + cost(u, v)
```

改成

```py
dist[v] = max(dist[u], cost(u, v))
```

### 2. 另外，在判斷一個新節點、應不應該放入 heap 時：

```cpp
if (next_effort >= dist[next_index]) continue;
```

這裡 "等於" 是必要的，因為：
- ```dist[v]``` 相等的話，沒必要再走；
- 防止走回頭路。

```cpp
// Runtime: 112 ms, Your runtime beats 97.51 % of cpp submissions.
// Memory Usage: 18.7 MB, Your memory usage beats 89.74 % of cpp submissions.

int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size(), w = heights[0].size();
    vector<int> dirs = {0, -1, 0, 1, 0};
    vector<int> dist(h * w, INT_MAX);
    dist[0] = 0;
    using Node = pair<int, int>;
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [effort, index] = q.top(); q.pop();
        if (index == h * w - 1) return effort;
        if (dist[index] < effort) continue; // heap 裡的 effort，不一定是最新的
        int y = index / w;
        int x = index % w;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i];
            int nx = x + dirs[i + 1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            int next_index = ny * w + nx;
            int next_effort = max(effort, abs(heights[y][x] - heights[ny][nx]));
            if (next_effort >= dist[next_index]) continue;  // *
            q.emplace(dist[next_index] = next_effort, next_index);
        }
    }
    return -1;
}
```
