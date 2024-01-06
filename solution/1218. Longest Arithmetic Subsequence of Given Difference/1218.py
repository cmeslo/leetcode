class Solution:
    def longestSubsequence(self, arr: List[int], diff: int) -> int:
        dp = {}
        for x in arr:
            dp[x] = dp[x - diff] + 1 if (x - diff) in dp else 1
        return max(dp.values())
