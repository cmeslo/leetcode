# 123. Best Time to Buy and Sell Stock III

## Solution: DP

```cpp
int maxProfit(vector<int>& prices) {
    int hold1 = INT_MIN, sold1 = 0, hold2 = INT_MIN, sold2 = 0;
    for (int x : prices) {
        sold2 = max(sold2, hold2 + x);
        hold2 = max(hold2, sold1 - x);
        sold1 = max(sold1, hold1 + x);
        hold1 = max(hold1, -x);
    }
    return max(sold1, sold2);
}

// hold, sold

// hold1[i] = max(hold1[i-1], -prices[i]);
// sold1[i] = max(sold1[i-1], hold1[i-1] + prices[i]);
// hold2[i] = max(hold2[i-1], sold1[i-1] - prices[i]);
// sold2[i] = max(sold2[i-1], hold2[i-1] + prices[i]);
```
