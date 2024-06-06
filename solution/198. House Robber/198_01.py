class Solution:
    def rob(self, nums: List[int]) -> int:
        dp2 = dp1 = dpi = 0
        for x in nums:
            dpi = max(dp1, dp2 + x)
            dp2, dp1 = dp1, dpi
        return dpi
