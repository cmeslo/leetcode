class Solution {
public:
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
};
