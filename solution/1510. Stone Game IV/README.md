# 1510. Stone Game IV

## 1510_01.cpp

```cpp
// Your runtime beats 45.45 % of cpp submissions.
bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (dp[i - j * j]) continue;
            dp[i] = true;
            break;
        }
    }

    return dp[n];
}
```
