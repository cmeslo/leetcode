# 1293. Shortest Path in a Grid with Obstacles Elimination

## Solution 1: 暴力 BFS

```cpp
// Runtime: 224 ms, Your runtime beats 39.70 % of cpp submissions.
// Your memory usage beats 18.54 % of cpp submissions.

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        const vector<int> dirs = {0, -1, 0, 1, 0};
        queue<vector<int>> q;
        visited[0][0][k] = 1;
        q.push({0, 0, k});
        
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front(); q.pop();
                int y = cur[0], x = cur[1], remain = cur[2];
                for (int j = 0; j < 4; ++j) {
                    int ny = y + dirs[j];
                    int nx = x + dirs[j + 1];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    int cnt = remain - grid[ny][nx];
                    if (cnt < 0) continue;
                    if (visited[ny][nx][cnt]) continue;
                    if (ny == m - 1 && nx == n - 1) return step + 1;
                    visited[ny][nx][cnt] = 1;
                    q.push({ny, nx, cnt});
                }
            }
            ++step;
        }
        return -1;
    }
    
private:
    bool visited[40][40][1601];
};
```

## Solution 2: BFS + 剪枝

### 剪枝策略

對於同一個格子，如果曾經以更少的破墻次數到達，就沒有必要再走下去。

```cpp
// Runtime: 11 ms, Your runtime beats 94.94 % of cpp submissions.
// Memory Usage: 9.3 MB, Your memory usage beats 87.81 % of cpp submissions.

int shortestPath(vector<vector<int>>& grid, int k) {
    const vector<int> dirs = {0, -1, 0, 1, 0};
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1) return 0;

    vector<vector<int>> seen(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    seen[0][0] = k;
    q.emplace(0, k);
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [pos, power] = q.front();
            q.pop();
            int y = pos / n, x = pos % n;
            for (int i = 0; i < 4; ++i) {
                int ny = y + dirs[i];
                int nx = x + dirs[i + 1];
                int npos = ny * n + nx;
                if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                int npower = power - (grid[ny][nx] == 1);
                if (npower < 0 || seen[ny][nx] >= npower) continue;
                seen[ny][nx] = npower;
                if (ny == m - 1 && nx == n - 1) return step + 1;
                q.emplace(npos, npower);
            }
        }
        step++;
    }
    return -1;
}
```
