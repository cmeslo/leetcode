class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        long lcm_ab = lcm(a, b);
        long l = 1, r = 1e15;
        while (l < r) {
            long m = l + (r - l) / 2;
            if (m / a + m / b - m / lcm_ab < n)
                l = m + 1;
            else
                r = m;
        }
        return l % mod;
    }
    
    // long count(long m, int a, int b, long lcm_ab) {
    //     return m / a + m / b - m / lcm_ab;
    // }
    
//     long LCM(int a, int b) {
//         return (long) a * b / GCD(a, b);
//     }
    
//     long GCD(int a, int b) {
//         if (b == 0)
//             return a;
//         return GCD(b, a % b);
//     }
};
