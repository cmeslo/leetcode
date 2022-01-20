class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while (l <= r) {
            long long tmp = l * l + r * r;
            if (tmp == c)
                return true;
            if (tmp < c)
                ++l;
            else
                --r;
        }
        return false;
    }
};
