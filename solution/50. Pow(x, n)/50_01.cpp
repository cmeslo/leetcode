class Solution {
public:
    double myPow(double x, long n) {
        if (n < 0) return 1.0 / myPow(x, -n);
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        double res = myPow(x, n / 2);
        res *= res;
        if (n % 2) res *= x;
        return res;
    }
};
