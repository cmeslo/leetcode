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

## DP
原本在思考上面BFS的方法如何做剪枝，但發現其實每一格的值都是依賴於自身的上面和左面，是典型的DP問題，所以更改了做法：
```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```
