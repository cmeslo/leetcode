# 200. Number of Islands

## Solution 1: BFS

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

## Solution 2: DFS

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += grid[i][j] - '0';
                dfs(grid, i, j);
            }
        }
        return res;
    }
    
private:
    int m, n;
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '0') return;
        
        grid[y][x] = '0';
        for (int k = 0; k < 4; ++k)
            dfs(grid, y + dirs[k], x + dirs[k + 1]);
    }
    
};
```
