# 62. Unique Paths

同 63. Unique Paths II 解題思路一樣，每個格的值都是來源於它的上面和左面：
```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```
只要小心第一行和第一列即就可以。

## Solution 1: DP (62_01.cpp)

用二維數組實現，比較直觀。

```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}
```

## Solution 2: DP (62_02.cpp)

用一維數組實現。

```cpp
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}
```
