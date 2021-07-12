# 120. Triangle

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
