class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}
        for i in range(len(nums)):
            for j in range(i):
                d = nums[i] - nums[j]
                dp[i, d] = dp.get((j, d), 1) + 1
        return max(dp.values())
