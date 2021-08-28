# 695. Max Area of Island

## Solution: DFS

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
