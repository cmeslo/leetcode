class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold_txn0 = 0;
        int sold_txn1 = 0, hold_txn1 = INT_MIN;
        int sold_txn2 = 0, hold_txn2 = INT_MIN;
        
        for (int price : prices) {
            sold_txn2 = max(sold_txn2, hold_txn2 + price);
            hold_txn2 = max(hold_txn2, sold_txn1 - price);
            sold_txn1 = max(sold_txn1, hold_txn1 + price);
            hold_txn1 = max(hold_txn1, sold_txn0 - price);
        }
        
        return sold_txn2;
    }
};
