# 64. Minimum Path Sum

## 動態規劃
典型的DP問題

```cpp
dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
```
