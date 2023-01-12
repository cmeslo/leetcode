# 695. Max Area of Island

## Solution 1: DFS

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
    
private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        int cur = 1;
        for (int k = 0; k < 4; ++k) {
            int y = i + dirs[k];
            int x = j + dirs[k + 1];
            cur += dfs(grid, y, x);
        }
        return cur;
    }
};
```

## Solution 2: BFS

```cpp
int maxAreaOfIsland(vector<vector<int>>& grid) {
    const vector<int> dirs = {0, 1, 0, -1, 0};
    int res = 0;
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) continue;
            grid[i][j] = 0;
            q.emplace(i, j);
            int cur = 0;
            while (!q.empty()) {
                auto [y, x] = q.front(); q.pop();
                ++cur;
                for (int k = 0; k < 4; ++k) {
                    int ny = y + dirs[k];
                    int nx = x + dirs[k + 1];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n || grid[ny][nx] == 0) continue;
                    grid[ny][nx] = 0;
                    q.emplace(ny, nx);
                }
            }
            res = max(res, cur);
        }
    }
    return res;
}
```
