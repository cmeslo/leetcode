class Solution {
public:
    int arrangeCoins(int n) {
        int coins = 0;
        
        while (n-coins > coins) n -= coins++;
        
        return coins;
    }
};
