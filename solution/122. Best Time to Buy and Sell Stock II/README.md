# 122. Best Time to Buy and Sell Stock II

## Solution 1: Greedy

```cpp
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i + 1] > prices[i]) 
            profit += prices[i + 1] - prices[i];
    }
    return profit;
}
```

## Solution 2: DP

```cpp
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> sold(n + 1), hold(n + 1);
    sold[0] = 0;
    hold[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int p = prices[i - 1];
        sold[i] = max(sold[i - 1], hold[i - 1] + p);
        hold[i] = max({hold[i - 1], sold[i - 1] - p, sold[i] - p});
    }
    return sold[n];
}
```

or

```cpp
int maxProfit(vector<int>& prices) {
    int sold = 0, hold = INT_MIN;
    for (int i = 1; i <= prices.size(); ++i) {
        int p = prices[i - 1];
        int lastSold = sold;
        sold = max(sold, hold + p);
        hold = max(hold, lastSold - p);
    }
    return sold;
}
```
