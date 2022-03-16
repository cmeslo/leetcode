# 1293. Shortest Path in a Grid with Obstacles Elimination

## Solution 1: BFS

```cpp
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
