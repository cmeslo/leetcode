# 115. Distinct Subsequences

## Solution: DP

```
s = "rabbbit", t = "rabbit"

dp[i][j] := the number of distinct subsequences of s[0:i] which equals t[0:j].

ans = dp[m][n]

x x x x x i
Y Y Y j

[r a b b b] i t
[r a b b] i t

dp[i][j] = dp[i-1][j-1] if (s[i] == s[j])
           + dp[i-1][j] if (s[i] != s[j] or s[i] == s[j])
           
s = ' ', 'r', 'a', 'b'
t = ' '
ans = 1
```

### Code

```cpp
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<unsigned long>> dp(m + 1, vector<unsigned long>(n + 1, 0));
    s = '#' + s;
    t = '#' + t;

    for (int i = 0; i <= m; ++i) dp[i][0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i] == t[j])
                dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[m][n];
}
```
