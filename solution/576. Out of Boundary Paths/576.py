class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (n + 2) for _ in range(m + 2)]
        
        for i in range(1, m + 1):
            dp[i][0] = dp[i][n + 1] = 1
        for j in range(1, n + 1):
            dp[0][j] = dp[m + 1][j] = 1
        
        pre = [row[:] for row in dp]
        
        for k in range(maxMove):
            for i in range(1, m + 1):
                for j in range(1, n + 1):
                    dp[i][j] = (pre[i - 1][j] + pre[i + 1][j] + pre[i][j - 1] + pre[i][j + 1]) % MOD
            pre, dp = dp, pre
            
        return pre[startRow + 1][startColumn + 1]
    
