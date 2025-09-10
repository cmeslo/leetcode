class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        
        dp = [[float('inf')] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        
        for l in range(2, n + 1):
            for i in range(n):
                j = i + l - 1
                if j >= n:
                    break
                dp[i][j] = 1 + dp[i + 1][j]
                for k in range(i, j):
                    if s[i] == s[k]:
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j])
                if s[i] == s[j]:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1])
        
        return dp[0][n - 1]
    
