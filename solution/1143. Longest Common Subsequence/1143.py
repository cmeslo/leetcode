class Solution:
    def longestCommonSubsequence(self, A: str, B: str) -> int:
        m, n = len(A), len(B)
        dp = [[0] * (n + 1) for i in range(m + 1)]
        A = '#' + A
        B = '#' + B
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i] == B[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        
        return dp[m][n]
        
