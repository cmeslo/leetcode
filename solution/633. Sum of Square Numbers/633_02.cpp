class Solution {
public:
    bool judgeSquareSum(int c) {
        int m = sqrt(c);
        for (long a = 0; a <= m; ++a) {
            long b = round(sqrt(c - a * a));
            if (a*a + b*b == c) return true;
        }
        return false;
    }
};
