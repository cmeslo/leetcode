# 70. Climbing Stairs


## Space complexity: O(n)

```cpp
int climbStairs(int n) {
    if (n < 3) return n;
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

## Space complexity: O(1)
```cpp
int climbStairs(int n) {
    int dp2 = 0, dp1 = 1, dpi = 0;
    for (int i = 1; i <= n; ++i) {
        dpi = dp2 + dp1;
        dp2 = dp1;
        dp1 = dpi;
    }
    return dp1;
}
```
