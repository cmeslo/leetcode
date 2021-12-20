# 132. Palindrome Partitioning II

## Solution: DP

```
[x x x j] [x x x i] x x
dp[i] = min{dp[j] + 1} if valid(j + 1, i)

x x i [x x x] j x x
valid[i][j] = s[i] == s[j] && valid[i+1][j-1]
```

```cpp
int minCut(string s) {
    int n = s.size();
    vector<vector<int>> valid(n, vector<int>(n, 1));
    for (int len = 2; len <= n; ++len)
        for (int i = 0, j = i + len - 1; j < n; ++i, ++j)
            valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];

    vector<int> dp(n, n);
    for (int i = 0; i < n; ++i) {
        if (valid[0][i]) {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < i; ++j)
            if (valid[j + 1][i])
                dp[i] = min(dp[i], dp[j] + 1);
    }
    return dp[n - 1];
}
```
