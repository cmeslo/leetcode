# 188. Best Time to Buy and Sell Stock IV

這裡把 "買入"，看作是一次交易

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
