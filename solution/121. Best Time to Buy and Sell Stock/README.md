# 121. Best Time to Buy and Sell Stock

## Solution: DP

```cpp
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int min = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < min)
            min = prices[i];
        else
            profit = max(profit, prices[i] - min);
    }

    return profit;
}
```

or

```cpp
int maxProfit(vector<int>& prices) {
    int res = 0;
    int mn = prices[0];
    for (int p : prices) {
        res = max(res, p - mn);
        mn = min(mn, p);
    }
    return res;
}
```

or

```cpp
int maxProfit(vector<int>& prices) {
    int hold = INT_MIN, sold = 0;

    for (int price : prices) {
        sold = max(sold, hold + price);
        hold = max(hold, -price);
    }

    return sold;
}
```
