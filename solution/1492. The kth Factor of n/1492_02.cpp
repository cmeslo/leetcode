class Solution {
public:
    int kthFactor(int n, int k) {
        
        int x;
        
        for (x = 1; x * x <= n; ++x)
            if (n % x == 0 && --k == 0) return x;
        
        --x;
        for (x = (x * x == n ? x - 1 : x); x >= 1; --x) {
            if (n % x == 0 && --k == 0) return n / x;
        }
        
        return -1;
    }
};
