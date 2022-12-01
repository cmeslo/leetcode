# 322. Coin Change

## Solution - DP

背包問題

```cpp
int coinChange(vector<int>& coins, int amount) {
    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int x = 1; x <= amount; ++x) {
        for (int coin : coins) {
            if (x >= coin)
                dp[x] = min(dp[x], dp[x - coin] + 1);
        }
    }
    return dp[amount] != INF ? dp[amount] : -1;
}
```
