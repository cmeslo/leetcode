# 799. Champagne Tower

## 799_01.cpp

用二維數組保存每一層的 Champagne

用當前層，更新下一層：

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0));
    dp[0][0] = poured;

    for (int i = 0; i < query_row; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] > 1) {
                dp[i + 1][j    ] += (dp[i][j] - 1) / 2.0;
                dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
                dp[i][j] = 1.0;
            }
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}
```

or

用上一層，更新當前層

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0));
    dp[0][0] = poured;

    for (int i = 1; i <= query_row; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) dp[i][j] += max(0.0, (dp[i - 1][j - 1] - 1) / 2.0);
            if (j < i) dp[i][j] += max(0.0, (dp[i - 1][j    ] - 1) / 2.0);
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}
```
