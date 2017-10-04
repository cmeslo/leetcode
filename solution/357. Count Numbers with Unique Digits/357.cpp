class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, cur = 9;
        for (int i = 2; i <= n; ++i) {
            cur = cur * (9 - i + 2);
            res += cur;
        }
        return res;
    }
};
