class Solution {
public:
    int divide(int dividend, int divisor) {
        long quotient  = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        int a = abs(dividend);
        long b = abs(divisor);
        
        while (a >= b) {
            long c = b;
            long count = 1;
            while ((c << 1) <= a) { // 如果 c 乘以2後仍然小於 a，就讓她乘
                c <<= 1;
                count <<= 1;
            }
            quotient += count;
            a -= c;
        }
        
        if (quotient * sign > INT_MAX) // quotient * sign 是針對case (-2147483648, 1)，原本是 quotient > INT_MAX
            return INT_MAX;
        else
            return quotient * sign;
    }
};
