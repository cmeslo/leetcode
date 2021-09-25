# 778. Swim in Rising Water

## Solution: BFS + PQ

```cpp
int swimInWater(vector<vector<int>>& grid) {
    const vector<int> dirs = {0, -1, 0, 1, 0};

    int n = grid.size();
    int ans = INT_MIN;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    visited[0][0] = 1;
    q.emplace(grid[0][0], 0);

    while (!q.empty()) {
        auto [h, pos] = q.top(); q.pop();
        ans = max(ans, h);
        if (pos == n * n - 1) return ans;
        int y = pos / n;
        int x = pos % n;
        for (int k = 0; k < 4; ++k) {
            int ny = y + dirs[k];
            int nx = x + dirs[k + 1];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.emplace(grid[ny][nx], ny * n + nx);
        }
    }

    return ans;
}
```
