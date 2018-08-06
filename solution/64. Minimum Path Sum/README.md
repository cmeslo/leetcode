# 64. Minimum Path Sum

## BFS
雖然早就預料到會超時，但還是想試一下
```cpp
class Solution {
private:
    void bfs(vector<vector<int>>& grid, int& min, int sum, int x, int y) {
        int m = grid[0].size() - 1, n = grid.size() - 1;
        if (x > m || y > n) return;
        
        sum += grid[y][x];
        
        if (x == m && y == n) {
            min = sum < min ? sum : min;
            return;
        }
        
        bfs(grid, min, sum, x + 1, y);
        bfs(grid, min, sum, x, y + 1);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].size() == 0) return 0;
        int min = INT_MAX;
        bfs(grid, min, 0, 0, 0);
        return min;
    }
};
```
