# 322. Coin Change

## Solution - DP

背包問題

```cpp
int coinChange(vector<int>& coins, int amount) {
    const int k = amount + 1;
    vector<int> dp(amount + 1, k);
    dp[0] = 0;

    for (int x = 1; x <= amount; ++x) {
        for (int coin : coins) {
            if (x - coin >= 0)
                dp[x] = min(dp[x], dp[x - coin] + 1);
        }
    }
    return dp[amount] == k ? -1 : dp[amount];
}
```
