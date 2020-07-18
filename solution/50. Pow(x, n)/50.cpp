class Solution {
public:
    double myPow(double x, int n) {
        return myPowHelper(x, n);
    }

private:
    double myPowHelper(double x, long n) { // long n, for case: (2.00000, -2147483648)
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 1) return 1;
        
        if (n < 0) return myPowHelper(1/x, -n);
        
        double result = myPowHelper(x*x, n/2);
        if (n % 2) result *= x;
        return result;
    }
};
