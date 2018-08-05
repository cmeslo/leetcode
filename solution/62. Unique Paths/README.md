# 62. Unique Paths

同 63. Unique Paths II 解題思路一樣，每個格的值都是來源於它的上面和左面：
```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```
只要小心第一行和第一列即就可以。
