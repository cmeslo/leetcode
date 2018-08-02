# 63. Unique Paths II

## BFS
最初想用BFS來做，但會超時
```cpp
class Solution {
private:
    void bfs(vector<vector<int>>& obstacleGrid, int& sum, int x, int y) {
        if (x >= obstacleGrid[0].size() || y >= obstacleGrid.size()) return;
        if (obstacleGrid[y][x] == 1) return;
        if (x == obstacleGrid[0].size() - 1 && y == obstacleGrid.size() - 1) {
            sum += 1;
            return;
        }

        bfs(obstacleGrid, sum, x + 1, y);
        bfs(obstacleGrid, sum, x, y + 1);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int sum = 0;
        bfs(obstacleGrid, sum, 0, 0);
        return sum;
    }
};
```
