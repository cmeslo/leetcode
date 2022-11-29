# 1091. Shortest Path in Binary Matrix

## Solution: BFS

```cpp
// Your runtime beats 96.98 % of cpp submissions.
// Your memory usage beats 86.69 % of cpp submissions.

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1) return -1;

    queue<pair<int, int>> q;
    grid[0][0] = 1;
    q.emplace(0, 0);

    int ans = 0;
    while (!q.empty()) {
        ++ans;
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == m - 1) return ans;
            for (int d1 = -1; d1 <= 1; ++d1) {
                for (int d2 = -1; d2 <= 1; ++d2) {
                    int nx = x + d1, ny = y + d2;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[ny][nx] == 1) continue;
                    grid[ny][nx] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    return -1;
}
```

or

```cpp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1) return -1;

    queue<pair<int, int>> q;
    int steps = 1;
    grid[0][0] = 1;
    q.emplace(0, 0);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [i, j] = q.front(); q.pop();
            if (i == m - 1 && j == n - 1) return steps;
            for (int y = max(0, i - 1); y <= min(i + 1, n - 1); ++y) {
                for (int x = max(0, j - 1); x <= min(j + 1, n - 1); ++x) {
                    if (grid[y][x] == 1) continue;
                    grid[y][x] = 1;
                    q.emplace(y, x);
                }
            }
        }
        steps++;
    }
    return -1;
}
```
