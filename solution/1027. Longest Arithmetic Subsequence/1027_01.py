class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                d = nums[j] - nums[i]
                dp[j, d] = dp.get((i, d), 1) + 1
        return max(dp.values())
