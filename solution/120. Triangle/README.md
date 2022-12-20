# 120. Triangle

## Solution

### 寫法一：下至上(推薦)

```cpp
int minimumTotal(vector<vector<int>>& T) {
    int n = T.size();

    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            T[i][j] += min(T[i + 1][j], T[i + 1][j + 1]);

    return T[0][0];
}
```

or

```cpp
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back());

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; j++) {
            dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }

    return dp[0];
}
```

### 寫法二：上至下

```cpp
int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle.back().size();
    vector<int> dp(n, INT_MAX);
    dp[0] = triangle[0][0];
    for (int i = 1; i < m; ++i) {
        for (int j = triangle[i].size() - 1; j >= 0; --j) {
            if (j == 0)
                dp[j] = dp[j] + triangle[i][j];
            else if (j == triangle[i].size() - 1)
                dp[j] = dp[j - 1] + triangle[i][j];
            else
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
        }
    }

    return *min_element(dp.begin(), dp.end());
}
```
