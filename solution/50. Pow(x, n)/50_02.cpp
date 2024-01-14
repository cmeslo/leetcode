class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int N = abs(n);
        while (N > 0) {
            if (N % 2) res *= x;
            x *= x;
            N /= 2;
        }
        return n < 0 ? 1/res : res;
    }
};
