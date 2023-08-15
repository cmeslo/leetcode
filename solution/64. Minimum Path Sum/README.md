# 64. Minimum Path Sum

## Solution: DP

```cpp
dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
```

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (m == 0 || n == 0) return 0;
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    
    for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[m - 1][n - 1];
}
```

or

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][1] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[m][n];
}
```
