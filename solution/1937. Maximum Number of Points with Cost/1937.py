class Solution:
    def maxPoints(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        
        dp = [0] * n
        for i in range(m):
            pre = dp[:]
            mx = float('-inf')
            for j in range(n):
                mx = max(mx, pre[j] + j)
                dp[j] = max(dp[j], mx + A[i][j] - j)
            mx = float('-inf')
            for j in range(n - 1, -1, -1):
                mx = max(mx, pre[j] - j)
                dp[j] = max(dp[j], mx + A[i][j] + j)
        
        return max(dp)
    
