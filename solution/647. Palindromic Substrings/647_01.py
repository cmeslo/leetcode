class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[1] * n for _ in range(n)]
        res = 0
        for j in range(n):
            for i in range(j):
                dp[i][j] = 1 if s[i] == s[j] and dp[i + 1][j - 1] == 1 else 0
                res += dp[i][j]
        return res + n
    
