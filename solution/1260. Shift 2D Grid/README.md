# 1260. Shift 2D Grid

## Solution: Simulation

```cpp
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    auto M = grid;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int pos = i * n + j;
            int pos_new = (pos + k) % (m * n);
            int y = pos_new / n;
            int x = pos_new % n;
            M[y][x] = grid[i][j];
        }
    }
    return M;
}

// i, j -> i * n + j
// 0, 0 -> 1, 0

// 0 -> 3
// i*n+j -> i*n+j + k
```
