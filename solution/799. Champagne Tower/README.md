# 799. Champagne Tower

## 799_01.cpp

Your runtime beats 45.45 % of cpp submissions.

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

## 799_02.cpp

不用二維數組的方法：

Your runtime beats 91.58 % of cpp submissions.

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(query_row + 1);
    dp[0] = poured;

    for (int i = 0; i < query_row; ++i) {
        vector<double> tmp(query_row + 1);
        for (int j = 0; j <= i; ++j) {
            if (dp[j] > 1) {
                tmp[j    ] += (dp[j] - 1) / 2.0;
                tmp[j + 1] += (dp[j] - 1) / 2.0;
            }
        }
        dp.swap(tmp);
    }

    return min(1.0, dp[query_glass]);
}
```

or

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(query_row + 1);
    dp[0] = poured;

    for (int i = 1; i <= query_row; ++i) {
        vector<double> tmp(query_row + 1);
        for (int j = 0; j <= i; ++j) {
            if (j > 0) tmp[j] += max(0.0, (dp[j - 1] - 1) / 2.0);
            if (j < i) tmp[j] += max(0.0, (dp[j    ] - 1) / 2.0);
        }
        dp.swap(tmp);
    }

    return min(1.0, dp[query_glass]);
}
```

or

從右更新至左，連臨時數組都不用

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> glasses(query_row + 1);

    glasses[0] = poured;
    for (int i = 0; i < query_row; ++i) {
        for (int j = i; j >= 0; --j) {
            glasses[j + 1] += glasses[j] = max(0.0, (glasses[j] - 1) / 2.0);
        }
    }

    return min(1.0, glasses[query_glass]);
}
```
