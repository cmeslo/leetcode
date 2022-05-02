# 994. Rotting Oranges

## Solution: BFS

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const vector<int> dirs = {0, -1, 0, 1, 0};

    int cnt_fresh = 0;
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1)
                ++cnt_fresh;
            else if (grid[i][j] == 2)
                q.push(i * n + j);
        }
    }
    if (cnt_fresh == 0) return 0;

    int minutes = 0;
    while (!q.empty()) {
        for (int size = q.size(); size > 0; --size) {
            int i = q.front() / n;
            int j = q.front() % n;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y < 0 || y >= m || x < 0 || x >= n) continue;
                if (grid[y][x] == 0 || grid[y][x] == 2) continue;
                grid[y][x] = 2;
                q.push(y * n + x);
                if (--cnt_fresh == 0) return minutes + 1;
            }
        }
        ++minutes;
    }
    return cnt_fresh == 0 ? minutes : -1;
}
```
