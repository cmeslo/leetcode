# 309. Best Time to Buy and Sell Stock with Cooldown

## Solution 1: DP

space complexity: ```O(n)```

```cpp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    if (n < 1) return 0;

    vector<int> s0(n), s1(n), s2(n);

    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;

    for (int i = 1; i < n; ++i) {
        s0[i] = max(s0[i - 1], s2[i - 1]);
        s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
        s2[i] = s1[i - 1] + prices[i];
    }

    return max(s0[n - 1], s2[n - 1]);
}
```

## Solution 2: DP

space complexity: ```O(1)```

```cpp
int maxProfit(vector<int>& prices) {
    int rest = 0;
    int hold = INT_MIN;
    int sold = 0;

    for (const int& price : prices) {
        int pre_hold = hold;
        hold = max(rest - price, hold);
        rest = max(rest, sold);
        sold = pre_hold + price;
    }

    return max(rest, sold);
}
```
