# 188. Best Time to Buy and Sell Stock IV

## Solution: DP

### 寫法一（推薦）

有兩個細節問題要弄清楚：

1. 買入、賣出，哪一個才算是完成一次交易（或者兩個一起用，總共 2k 次交易）

    買入 或者 賣出 看作是一次交易都可以，關鍵是Base case、初始化條件不同。

2. 循環時 k 是倒序還是正序，為什麼正序倒序不影響結果？

    待補充。


這裡把 "買入"，看作是一次交易：

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (k > n/2) return max_profit_with_infinity_K(prices);
        
        vector<int> sold(k + 1, 0);
        vector<int> hold(k + 1, INT_MIN);
        
        for (int price : prices) {
            // for (int j = k; j > 0; j--) {
            for (int j = 1; j <= k; j++) {
                sold[j] = max(sold[j], hold[j] + price);
                hold[j] = max(hold[j], sold[j - 1] - price);
            }
        }
        
        return sold[k];
    }
    
private:
    int max_profit_with_infinity_K(vector<int>& prices) {
        int sold = 0, hold = INT_MIN;
        
        for (int price : prices) {
            int prev_sold = sold;
            sold = max(sold, hold + price);
            hold = max(hold, prev_sold - price);
        }
        
        return sold;
    }
};
```

reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems


### 寫法二

```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> hold(n + 1, vector<int>(k + 1));
    vector<vector<int>> sold(n + 1, vector<int>(k + 1));

    for (int j = 0; j <= k; ++j)
        hold[0][j] = INT_MIN;

    for (int i = 1; i <= n; ++i) {
        int p = prices[i - 1];
        for (int j = 1; j <= k; ++j) {
            hold[i][j] = max(hold[i - 1][j], sold[i - 1][j - 1] - p);
            sold[i][j] = max(sold[i - 1][j], hold[i - 1][j] + p);
        }
    }

    return sold[n][k];
}

// hold[i][j] := the maximum profit afte finished j transaction at the end of i-th day and hold stock
// sold[i][j] := the maximum profit afte finished j transaction at the end of i-th day and do not have stock

// hold[i][j] = max(hold[i - 1][j], sold[i - 1][j] - prices[i]);

// sold[i][j] = max(sold[i - 1][j], hold[i - 1][j - 1] + prices[i]);

// dp[n][k][0] <--ans
```
