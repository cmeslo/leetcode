# 132. Palindrome Partitioning II

## Solution 1: DP

```
[x x x j] [x x x i] x x
dp[i] = min{dp[j] + 1} if valid(j + 1, i)

x x i [x x x] j x x
valid[i][j] = s[i] == s[j] && valid[i+1][j-1]
```

```cpp
// Your runtime beats 44.57 % of cpp submissions.
// Your memory usage beats 28.26 % of cpp submissions.

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

## Solution 2: DP

```
x x x [i x m x j] x x
dp[j] = min{dp[i-1] + 1} if valid(i, j)
```

```cpp
// Your runtime beats 99.71 % of cpp submissions.
// Your memory usage beats 96.65 % of cpp submissions.

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, n);
    for (int m = 0; m < n; ++m) {
        for (int i = m, j = m; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
            if (i == 0)
                dp[j] = 0;
            else
                dp[j] = min(dp[j], dp[i - 1] + 1);
        }
        for (int i = m, j = m + 1; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
            if (i == 0)
                dp[j] = 0;
            else
                dp[j] = min(dp[j], dp[i - 1] + 1);
        }
    }
    return dp[n - 1];
}
```

[reference](https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-132-palindrome-partitioning-ii/)
