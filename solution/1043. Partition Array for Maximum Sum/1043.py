class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], K: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        
        for i in range(1, n + 1):
            mx = 0
            for k in range(1, min(K, i) + 1):
                mx = max(mx, arr[i - k])
                dp[i] = max(dp[i], mx * k + dp[i - k])
        
        return dp[-1]
    
