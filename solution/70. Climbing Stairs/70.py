class Solution:
    def climbStairs(self, n: int) -> int:
        dp2 = dpi = 0
        dp1 = 1
        for i in range(n):
            dpi = dp2 + dp1
            dp2, dp1 = dp1, dpi
        return dpi
    
