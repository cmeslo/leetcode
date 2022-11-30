# 63. Unique Paths II

## DP

```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```

### 寫法一：
```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int up = i - 1 >= 0 ? dp[i - 1][j] : 0;
            int left = j - 1 >= 0 ? dp[i][j - 1] : 0;
            dp[i][j] += obstacleGrid[i][j] ? 0 : up + left;
        }
    }
    return dp[m - 1][n - 1];
}
```

### 寫法二：

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}
```

### 寫法三：

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) return 0;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1])
                dp[j] = 0;
            else
                dp[j] += dp[j - 1];
        }
    }
    return dp[n];
}
```
