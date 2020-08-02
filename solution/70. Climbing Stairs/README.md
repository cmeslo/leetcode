#

## space complexity: O(n)

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

## space complexity: O(1)
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;

    int ans = 0, step1 = 1, step2 = 2;
    for (int i = 3; i <= n; i++) {
        ans = step1 + step2;
        step1 = step2;
        step2 = ans;
    }

    return ans;
}
```
