# 200. Number of Islands

```cpp
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const vector<int> dirs = {0, -1, 0, 1, 0};

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                queue<pair<int, int>> q;
                grid[i][j] = '0';
                q.emplace(i, j);
                while (!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ny = y + dirs[k];
                        int nx = x + dirs[k + 1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (grid[ny][nx] == '0') continue;
                        grid[ny][nx] = '0';
                        q.emplace(ny, nx);
                    }
                }
                ++ans;
            }
        }
    }
    return ans;
}
```
