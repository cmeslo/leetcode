# 583. Delete Operation for Two Strings

## Solution: DP

### 動態轉移方程：

```py
w1: x x x x x x x i
w2: x x x x x j 
```

```py
dp[i][j] = dp[i-1][j-1] if w1[i] == w2[j]
           min(dp[i-1][j], dp[i][j-1]) + 1 if w1[i] != w2[j]
```

### Code:

```cpp
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[m][n];
}
```
