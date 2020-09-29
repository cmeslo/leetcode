class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0;
        
        for (int price : prices) {
            sold = max(sold, hold + price);
            hold = max(hold, -price);
        }
        
        return sold;
    }
};
