# 980. Unique Paths III

## Solution: DFS

普通 DFS，加上到達終點時，看看 0 的數目，確保走完所有路

```cpp
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        h = grid.size(), w = grid[0].size();
        int startY, startX;
        int zeros = 0;
        
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 0)
                    ++zeros;
                else if (grid[y][x] == 1)
                    startY = y, startX = x;
            }
        }
        
        dfs(grid, startY, startX, zeros, ans);
        return ans;
    }

private:
    int h, w;
    
    void dfs(vector<vector<int>>& grid, int y, int x, int zeros, int& ans) {
        if (y < 0 || y >= h || x < 0 || x >= w || grid[y][x] == -1) return;
        if (grid[y][x] == 2) {
            if (zeros == 0) ++ans;
            return;
        }
        
        if (grid[y][x] == 0) --zeros;
        
        grid[y][x] = -1;
        dfs(grid, y - 1, x, zeros, ans);
        dfs(grid, y + 1, x, zeros, ans);
        dfs(grid, y, x - 1, zeros, ans);
        dfs(grid, y, x + 1, zeros, ans);
        grid[y][x] = 0;
    }
};
```

dfs 返回 int 的寫法：

```cpp
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startY = -1, startX = -1;
        int empty = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++empty;
                } else if (grid[i][j] == 1) {
                    startY = i;
                    startX = j;
                }
            }
        }
        return dfs(grid, startY, startX, empty + 1);
    }

private:
    int dfs(vector<vector<int>>& grid, int y, int x, int empty) {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) return 0;
        if (grid[y][x] == -1) return 0;
        if (grid[y][x] == 2) return empty == 0;

        grid[y][x] = -1;
        int res = dfs(grid, y - 1, x, empty - 1)
                + dfs(grid, y, x - 1, empty - 1)
                + dfs(grid, y + 1, x, empty - 1)
                + dfs(grid, y, x + 1, empty - 1);
        grid[y][x] = 0;
        return res;
    }
};
```
