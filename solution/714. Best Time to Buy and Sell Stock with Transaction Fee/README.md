# 714. Best Time to Buy and Sell Stock with Transaction Fee

## Solution - DP

### Space complexity O(n):

```cpp
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));

    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1] + prices[i - 1] - fee, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][1]);
    }

    return dp[n][0];
}
```

### Space complexity O(1):

```cpp
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    int sold = 0;
    int hold = -prices[0];

    for (int price : prices) {
        int sold_old = sold;
        sold = max(hold + price - fee, sold);
        hold = max(sold_old - price, hold);
    }

    return sold;
}
```
