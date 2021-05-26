class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int sold = 0;
        int hold = - prices[0];
        
        for (int price : prices) {
            int sold_old = sold;
            sold = max(hold + price - fee, sold);
            hold = max(sold_old - price, hold);
        }
        
        return sold;
    }
};
