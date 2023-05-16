# 279. Perfect Squares

## Solution 1: DP

因為題目要求最少組成數目，所以很自然就想到用DP做

|   | 1         | 4         | 9 |
|---|-----------|-----------|---|
| 1 | 1+dp[1-1] | X         | X |
| 2 | 1+dp[2-1] | X         | X |
| 3 | 1+dp[3-1] | X         | X |
| 4 | 1+dp[4-1] | 1         | X |
| 5 | 1+dp[5-1] | 1+dp[5-4] | X |
| 6 | 1+dp[6-1] | 1+dp[6-4] | X |

```cpp
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[i-j*j]);
        }
    }
    return dp[n];
}
```

## Solution 2: BFS

最短路問題

```cpp
int numSquares(int n) {
    int res = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        for (int size = q.size(); size > 0; --size) {
            int cur = q.front(); q.pop();
            for (int i = 1; i*i <= cur; ++i) {
                if (cur == i*i) return res + 1;
                q.push(cur - i*i);
            }
        }
        ++res;
    }
    return n;
}
```
