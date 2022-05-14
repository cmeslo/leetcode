class Solution {
public:
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
};
