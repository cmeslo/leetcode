# 221. Maximal Square

## Solution: DP

```cpp
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int sz = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!i || !j || matrix[i][j] == '0') {
                dp[i][j] = matrix[i][j] - '0';
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            sz = max(sz, dp[i][j]);
        }
    }
    return sz * sz;
}
```

節省空間:

```cpp
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int sz = 0;
    vector<int> cur(n), pre(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!i || !j || matrix[i][j] == '0') {
                cur[j] = matrix[i][j] - '0';
            } else {
                cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
            }
            sz = max(sz, cur[j]);
        }
        // fill(pre.begin(), pre.end(), 0);
        swap(pre, cur);
    }
    return sz * sz;
}
```
