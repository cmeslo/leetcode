class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) return n;
        int low = 0, high = n;
        
        while (low < high) {
            int mid = low + (high-low)/2;
            long total = (long) mid*(1+mid)/2;
            if (total == n) return mid;
            if (total < n) low = mid + 1;
            else high = mid;
        }
        
        return low - 1;
    }
};
