class Solution {
public:
    int climbStairs(int n) {
        int dp2 = 0, dp1 = 1, dpi = 0;
        for (int i = 1; i <= n; ++i) {
            dpi = dp2 + dp1;
            dp2 = dp1;
            dp1 = dpi;
        }
        return dp1;
    }
};
