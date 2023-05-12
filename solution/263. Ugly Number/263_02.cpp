class Solution {
public:
    bool isUgly(int n) {
        for (int x = 2; x <= 5 && n; ++x) {
            while (n % x == 0)
                n /= x;
        }
        return n == 1;
    }
};
