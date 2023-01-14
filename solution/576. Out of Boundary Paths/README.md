# 576. Out of Boundary Paths

## Solution: DP

由邊界走到起點。

### 寫法一(推薦)

```cpp
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    const int Mod = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n));
    auto temp = dp;
    for (int k = 0; k < maxMove; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                long up = i - 1 < 0 ? 1 : dp[i - 1][j];
                long down = i + 1 >= m ? 1 : dp[i + 1][j];
                long left = j - 1 < 0 ? 1 : dp[i][j - 1];
                long right = j + 1 >= n ? 1 : dp[i][j + 1];
                temp[i][j] = (up + down + left + right) % Mod;
            }
        }
        swap(temp, dp);
    }
    return dp[startRow][startColumn];
}
```

### 寫法二

```cpp
// dp[i][j][k] = dp[i - 1][j][k - 1] + 
//               dp[i][j - 1][k - 1] +
//               dp[i + 1][j][k - 1] +
//               dp[i][j + 1][k - 1]

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    const int Mod = 1e9 + 7;
    long res = 0;

    vector<vector<vector<long>>> dp(m + 2, vector<vector<long>>(n + 2, vector<long>(maxMove + 1)));
    startRow++;
    startColumn++;

    for (int i = 1; i <= m; ++i)
        dp[i][0][0] = dp[i][n + 1][0] = 1;

    for (int j = 1; j <= n; ++j)
        dp[0][j][0] = dp[m + 1][j][0] = 1;

    for (int k = 1; k <= maxMove; ++k) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j][k] = (dp[i - 1][j][k - 1] + 
                              dp[i][j - 1][k - 1] +
                              dp[i + 1][j][k - 1] +
                              dp[i][j + 1][k - 1]) % Mod;

                if (i == startRow && j == startColumn)
                    res = (res + dp[i][j][k]) % Mod;
            }
        }
    }

    return res;
}
```
