class Solution {
public:
    int arrangeCoins(int n) {
        // x(1 + x)/2 = n
        // x^2 + x - 2n = 0
        // x = (-1 + sqrt(1 + 8*n))/2
        return (int) (-1 + sqrt(1 + 8*(long)n))/2;
    }
};
